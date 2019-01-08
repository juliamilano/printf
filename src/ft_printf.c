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

int            ft_write(t_data *f)
{
    size_t len;

    len = ft_strlen(f->result);
    f->i_p += len;
    write(1, f->result, len);
    return (len);
}
int            ft_write_format(t_data *f, const char c)
{
    f->i_p++;
    write(1, &c, 1);
    return (1);
}
int ft_printf(const char *format, ...)
{
	t_data      f;
    int         i;
    int         cnt_i;

    if (!format)
        return (0);
    va_start(f.list, format);
    i = -1;
    cnt_i = 0;
    empty_struct(&f);
    while (format[++i] != '\0') 
    {
        //printf();
        if (format[i] == '%' && format[i + 1] == '%' && f.i_p++)
			ft_write_format(&f, format[i++]);
        else if (format[i] == '%')
        {
            if (check_data(format + i + 1, &cnt_i, &f))
            {
                f.data = ft_strsub(format, i + 1, cnt_i + 1);
                //printf("\n arr |%s|\n", f.data );
                def_all(&f);
			    def_type(&f);
                print_res(&f);
                i = i + cnt_i + 1;
                cnt_i = 0;
                free_all_mem(&f);
            }
            else
                ft_write_format(&f, format[i]);
        }
        else 
            ft_write_format(&f, format[i]);
    }
    va_end(f.list);
    return (f.i_p);
}

// void ft_write_buff(t_data *f, char c)
// {
//     (c != 0) ? f->buff[f->i_p++] = c : 0;
// }
int print_res(t_data *f)
{
    if (f->type == 'd' && d_treat(f))
        ft_write(f);
    else if (f->type == 'c' && s_treat(f))
        ft_write(f);
    else if (f->type == 's' && s_treat(f))
        ft_write(f);

    return 1;
}