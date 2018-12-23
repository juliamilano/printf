/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:49:53 by ytrubach          #+#    #+#             */
/*   Updated: 2018/12/18 16:49:56 by ytrubach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void empty_struct(t_data *f)
{
    f->data = NULL;
    f->flag = NULL;
    f->width = NULL;
    f->prec = NULL;
    f->spec = NULL;
	f->type = 0;
    f->output = NULL;
    f->result = NULL;
}

int ft_printf(const char *format, ...)
{
	t_data      f;
    int         i;
    int         cnt_i;
    va_list     list;

    if (!format)
        return (0);
    va_start(list, format);
    i = -1;
    cnt_i = 0;
    empty_struct(&f);
    while (format[++i] != '\0') 
    {
        if (format[i] == '%' && format[i + 1] == '%')
			write(1, &format[i++],1);
        else if (format[i] == '%')
        {
            if (check_data(format + i + 1, &cnt_i, &f))
            {
                f.data = ft_strsub(format, i + 1, cnt_i + 1);
                //printf("\n arr %s\n", f.data );
                def_all(&f);
			    def_type(list, &f);
                print_res(&f);
                 i = i + cnt_i + 1;
                 cnt_i = 0;
                 free(f.data);
            }
            else 
                write(1, &format[i],1);
        }
        else 
            write(1, &format[i],1);
    }
    va_end(list);
    return (0);
}
