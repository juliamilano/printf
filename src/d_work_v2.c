#include "ft_printf.h"

char *creat_s_width(t_data  *f, char symb)
{

	int len;
	char *s;
	int i;

	i = -1;
	s = NULL;
	len = (int)ft_strlen(f->output);
	if (ft_strchr(f->output, '+') || ft_strchr(f->output, '-'))
 	 	len--;
	(f->dfill.zero_prec) ? len += (int)ft_strlen(f->dfill.zero_prec) : 0;
	(f->dfill.znak) ? len += (int)ft_strlen(f->dfill.znak) : 0;
	if (f->width && len < ft_atoi(f->width))
	{
		s = (char *)malloc(sizeof(char) * ft_atoi(f->width) - len + 1);
		while (++i < ft_atoi(f->width) - len)
			s[i] = symb;
		s[i] = '\0';
	}
	return (s);
}

char *creat_s_prec(t_data  *f, char symb)
{
 	char *s;
 	int len;
	int output;
	int i;

	i = -1;
 	len = (int)ft_strlen(f->output);
	if(ft_strchr(f->output, '+') || ft_strchr(f->output, '-'))
	 	len--;
	output = len;
	s = NULL;
	if (f->prec && len < ft_atoi(f->prec) && (s = (char *)malloc(sizeof(char) * ft_atoi(f->prec) - output + 1)))
	{
		len = ft_atoi(f->prec);
		while (++i < len - output)
			s[i] = symb;
		s[i] = '\0';
	}	
 	return (s);
}

void join_data_v1(t_data  *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f->dfill.space_width != NULL)
		while (f->dfill.space_width[j] != '\0')
			f->result[i++] = f->dfill.space_width[j++];
	if (f->dfill.znak[0] != '\0')
		f->result[i++] = f->dfill.znak[0];
	j = 0;
	if (f->dfill.zero_prec != NULL)
		while (f->dfill.zero_prec[j] != '\0')
			f->result[i++] = f->dfill.zero_prec[j++];
	j = (ft_strchr(f->output, '+') || ft_strchr(f->output, '-')) ? 1 : 0;
	if (i < f->memory)
		while (i < f->memory)
			f->result[i++] = f->output[j++];
	printf("f->result |%s|\n", f->result);
}
void join_data_v2(t_data  *f)
{
	int i;
	int j;

	i = 0;
	if (f->dfill.znak[0] != '\0')
		f->result[i++] = f->dfill.znak[0];
	j = 0;
	if (f->dfill.space_width != NULL)
		while (f->dfill.space_width[j] != '\0')
			f->result[i++] = f->dfill.space_width[j++];
	j = 0;
	if (f->dfill.zero_prec != NULL)
		while (f->dfill.zero_prec[j] != '\0')
			f->result[i++] = f->dfill.zero_prec[j++];
	j = (ft_strchr(f->output, '+') || ft_strchr(f->output, '-')) ? 1 : 0;
	if (i < f->memory)
		while (i < f->memory)
			f->result[i++] = f->output[j++];
	printf("f->result |%s|\n", f->result);
}
void rev_join_data_v2(t_data  *f)
{
	int i;
	int j;

	i = 0;
	if (f->dfill.znak[0] != '\0')
		f->result[i++] = f->dfill.znak[0];
	j = 0;
	if (f->dfill.zero_prec != NULL)
		while (f->dfill.zero_prec[j] != '\0')
			f->result[i++] = f->dfill.zero_prec[j++];
	j = (ft_strchr(f->output, '+') || ft_strchr(f->output, '-')) ? 1 : 0;
	if (i < f->memory)
		while (f->output[j])
			f->result[i++] = f->output[j++];
	j = 0;
	if (f->dfill.space_width != NULL)
		while (f->dfill.space_width[j] != '\0')
			f->result[i++] = f->dfill.space_width[j++];
	printf("f->result |%s|\n", f->result);
}

void rev_j_data_space(t_data  *f)
{
	int i;
	int j;

	i = 0;
	f->result[i++] = ' ';
	j = 0;
	if (f->dfill.zero_prec != NULL)
		while (f->dfill.zero_prec[j] != '\0')
			f->result[i++] = f->dfill.zero_prec[j++];		
	j = 0;
	if (i < f->memory)
		while (f->output[j])
			f->result[i++] = f->output[j++];
	j = 0;
	if (f->dfill.space_width != NULL)
		while (f->dfill.space_width[j + 1] != '\0')
			f->result[i++] = f->dfill.space_width[j++];
	//printf(" rev_j_data_space f->result |%s|\n", f->dfill.space_width);
}
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
int d_treat(t_data  *f)
{
	obnull_dfill(f);
	fill__dfill(f);
	if (!(ft_strchr(f->flag, '-')) && (ft_strchr(f->flag, '0') &&
		(ft_strchr(f->output, '-') || ft_strchr(f->flag, '+'))))
			join_data_v2(f);
	else if (!(ft_strchr(f->flag, '-')))
		join_data_v1(f);
	else if (ft_strchr(f->flag, '-') && ft_strchr(f->flag, ' ') && f->dfill.znak[0] == '\0')
		rev_j_data_space(f);
	else if (ft_strchr(f->flag, '-'))
		rev_join_data_v2(f);

	printf("// f->result |%s|\n", f->result);
	 //printf("f->dfill.znak |%s| \n f->dfill.zero_prec  |%s|\n f->dfill.space_width |%s|\n", f->dfill.znak , f->dfill.zero_prec , f->dfill.space_width);
    return 1;
}

