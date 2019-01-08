#include "ft_printf.h"

void fill__dfill(t_data  *f)
{
	if (ft_strchr(f->output, '-') || ft_strchr(f->flag, '+'))
	 	f->dfill.znak = (ft_atoi(f->output) < 0) ? "-":  "+";
	f->dfill.zero_prec = creat_s_prec(f, '0');
	if(!(ft_strchr(f->flag, '0')))
		f->dfill.space_width = creat_s_width(f, ' ');
	else 
		f->dfill.space_width = creat_s_width(f, '0');
}

void fill__sfill(t_data  *f)
{
    int len;

    len = (int)ft_strlen(f->output);
    if (f->prec && (int)ft_strlen(f->output) >= ft_atoi(f->prec))
    	len = ft_atoi(f->prec);
    if (f->prec && (int)ft_strlen(f->output) < ft_atoi(f->prec))
     	len = (int)ft_strlen(f->output);
	if (f->width != NULL && len < ft_atoi(f->width))
		f->dfill.space_width = str_creat_s_width(f, f->memory - len);

	//printf("f->dfill.znak |%s| \n f->dfill.zero_prec  |%s|\n f->dfill.space_width |%s|\n", f->dfill.znak , f->dfill.zero_prec , f->dfill.space_width);
}