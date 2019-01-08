#include "ft_printf.h"

char *str_creat_s_width(t_data  *f, int q)
{
	char *s;
	int i;
	char c;

	i = -1;
	s = NULL;
	c = (ft_strchr(f->flag, '0') && !ft_strchr(f->flag, '-')) ? '0' : ' ';
	if (f->width && q)
	{
		if (!(s = (char *)malloc(sizeof(char) * q + 1)))
            return (NULL);
	   	while (++i < q)
			s[i] = c;
		s[i] = '\0';
	}
	return (s);
}

void join_data_s(t_data  *f)
{
    int i;
	int j;
    int len;

	i = 0;
	j = 0;
	if (f->dfill.space_width != NULL)
		while (f->dfill.space_width[j] != '\0')
			f->result[i++] = f->dfill.space_width[j++];
	len = f->memory - i;
	j = 0;
	if (i < f->memory)
		while (len-- > 0)
			f->result[i++] = f->output[j++];

}

void r_join_data_s(t_data  *f)
{
    int i;
	int j;
    int len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(f->output);
	if (f->dfill.space_width != NULL)
    	len = f->memory - (int)ft_strlen(f->dfill.space_width);
	while (len--)
		f->result[i++] = f->output[j++];
	j = 0;
	if (f->dfill.space_width != NULL)
		while (i < f->memory && f->dfill.space_width[j] != '\0')
 			f->result[i++] = f->dfill.space_width[j++];
}



int s_treat(t_data  *f)
{
	obnull_dfill(f);
	fill__sfill(f);

	if (!(ft_strchr(f->flag, '-')))
		join_data_s(f);
    else if (ft_strchr(f->flag, '-'))
        r_join_data_s(f);

	//printf("// f->output  %s| f->result %s|\n", f->output, f->result);
	//printf("f->dfill.znak |%s| \n f->dfill.zero_prec  |%s|\n f->dfill.space_width |%s|\n", f->dfill.znak , f->dfill.zero_prec , f->dfill.space_width);
    free_fill_mem(f);
	return 1;
}