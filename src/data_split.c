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

char	*create_char(int n)
{
	char	*x;
    char    symb;

	if (!(x = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	symb = (char)n;
	x[0] = symb;
	x[1] = '\0';
	return (x);
}



void    def_type(t_data *f)
{
    if (validinput(f->data))
    {
        
        if (ft_strchr(f->data, 'd') && (f->type = 'd') && f->spec && (ft_strnequ(f->spec, "ll", 2)))
		    f->output = ft_litoa(va_arg(f->list, long long int));
        else if (ft_strchr(f->data, 'd') && (f->type = 'd') && f->spec && (ft_strchr(f->spec, 'l')))
            f->output = ft_litoa(va_arg(f->list, long int));
        else if (ft_strchr(f->data, 'd') && (f->type = 'd') && f->spec && (ft_strnequ(f->spec, "hh", 2)))
		    f->output = ft_litoa((signed char)va_arg(f->list, int));
        else if (ft_strchr(f->data, 'd') && (f->type = 'd') && f->spec && (ft_strnequ(f->spec, "h", 1)))
            f->output = ft_litoa((short int)va_arg(f->list, int));
        else if (ft_strchr(f->data, 'd') && (f->type = 'd'))
		    f->output = ft_litoa(va_arg(f->list, int));
        else if (ft_strchr(f->data, 'c') && (f->type = 'c')) // without spec
            f->output = create_char(va_arg(f->list, int));
        else if (ft_strchr(f->data, 's') && (f->type = 's')) // without spec
            f->output = va_arg(f->list, char *);
        //else if (ft_strchr(f->data, 'i') && (f->type = 'i'))
		//    f->output = ft_itoa(va_arg(list, int));
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
        // else if (ft_strchr(f->data, 'p') && (f->type = 'p'))
        //     output = va_arg(listPointer, void *);
        //ft_putstr(f->output);
     }
    // printf("f->output |%s| \n", f->output);
    (f->type == 'd') ? cnt_mem_d(f) : 0;
    (f->type == 's' || f->type == 'c') ? cnt_mem_s(f) : 0;
     //f->result = f->output;
     //def_var(f, output);
    // treatment // output
}
