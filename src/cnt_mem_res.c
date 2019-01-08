#include "ft_printf.h"

int	cnt_mem_s(t_data *f)
{
	int memory;

    memory = (int)ft_strlen(f->output);

    if (f->prec && (int)ft_strlen(f->output) >= ft_atoi(f->prec))
    	memory = ft_atoi(f->prec);
    if (f->prec && (int)ft_strlen(f->output) < ft_atoi(f->prec))
     	memory = (int)ft_strlen(f->output);
    if (f->width != NULL && memory < ft_atoi(f->width))
     	memory = ft_atoi(f->width);
    f->result = (char *)malloc(sizeof(char) * memory + 1);
    f->result[memory] = '\0';
    f->memory = memory;
    //printf("f->memory%d\n", f->memory);
    return (1);
}

int	cnt_mem_d(t_data *f)
{
	int memory;

	memory = (int)ft_strlen(f->output);
    if (ft_strchr(f->output, '+') || ft_strchr(f->output, '-'))
 	 	memory--;
	if (f->prec && memory < ft_atoi(f->prec))
		memory = ft_atoi(f->prec);
	if ((ft_strchr(f->flag, '+') || ft_strchr(f->output, '-')) && ++memory) 
        ;
	if (f->width != NULL && memory < ft_atoi(f->width))
		memory = ft_atoi(f->width);
	f->result = (char *)malloc(sizeof(char) * memory + 1);
	f->result[memory] = '\0';
    f->memory = memory;
    //printf("f->memory%d\n", f->memory);
	return (1);
}