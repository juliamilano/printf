/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:55:19 by ytrubach          #+#    #+#             */
/*   Updated: 2018/12/18 16:55:22 by ytrubach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int     validinput(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (ft_isalpha(s[i]) || ft_isdigit(s[i]) ||
		s[i] == '#' || s[i] == '.' ||
		s[i] == '+' || s[i] == '-' || s[i] == ' ')
			i++;
        else
		return (0);
    }
    return (1);
}

void	cnt_mem(t_data *f)
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
}

void    def_type(va_list list, t_data *f)
{
    if (validinput(f->data))
    {
        if (ft_strchr(f->data, 'd') && (f->type = 'd'))
		f->output = ft_itoa(va_arg(list, int));
        else if (ft_strchr(f->data, 'i') && (f->type = 'i'))
		f->output = ft_itoa(va_arg(list, int));
        // else if (ft_strchr(f->data, 'o') && (f->type = 'o'))
        //     output = ft_itoa(va_arg(listPointer, int));
        // else if (ft_strchr(f->data, 'u') && (f->type = 'u'))
        //     output = ft_itoa(va_arg(listPointer, int));
        // else if (ft_strchr(f->data, 'X') && (f->type = 'X'))
        //     output = ft_itoa(va_arg(listPointer, int));
        // else if (ft_strchr(f->data, 'x') && (f->type = 'x'))
        //     output = ft_itoa(va_arg(listPointer, int));
        // else if (ft_strchr(f->data, 'f') && (f->type = 'f'))
        //     output = ft_itoa(va_arg(listPointer, int));
       // else if (ft_strchr(f->data, 'c') && (f->type = 'c'))
       //     f->output[0] = va_arg(listPointer, char);
        //else if (ft_strchr(f->data, 's') && (f->type = 's'))
        //    output = va_arg(listPointer, char *);
        // else if (ft_strchr(f->data, 'p') && (f->type = 'p'))
        //     output = va_arg(listPointer, void *);
        //ft_putstr(f->output);
     }
      cnt_mem(f);
     //f->result = f->output;
     //def_var(f, output);
    // treatment // output
}
