/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytrubach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:50:11 by ytrubach          #+#    #+#             */
/*   Updated: 2018/12/18 16:50:14 by ytrubach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_flags(char c)
{
    return (c == ' ' || c == '#' ||
        c == 48 || c == '+' || c == '-') ? 1 : 0;
}

int check_type(char c, t_data *f)
{
    char *data_type;
    int i;

    i = 0;
    data_type = "cspdiouxXf";
    while (data_type[i] != '\0')
    {
        if (data_type[i] == c)
        {
            (f) ? (f->type = c) : 0;
            return (1);
        }
        i++;
    }

    return (0);
}

int     check_data(const char *s, int *cnt_i, t_data *f)
{
    while (*s != '\0' && !(check_type(*s, f)))
    {
        (*cnt_i)++;
        s++;
    }
    if (*s == '\0')
        return (0);
    return (1);
}

