
#include "ft_printf.h"

// char *d_width(char *s, char *size, char c) // 33, 5, 0 00033
// {
//     char *res;
//     int len;
//     int i;
//     int j;

//     j = 0;
//     i = 0;
//     if ((len = 0) && (int)ft_strlen(s) > ft_atoi(size))
//         len = (int)ft_strlen(s);
//     else if ((int)ft_strlen(s) <= ft_atoi(size))
//         len = ft_atoi(size);
//     if (!(res = (char *)malloc(sizeof(char) * len + 1)))
//         return NULL;
//     while (len--)
//     {
//         while (i < (ft_atoi(size) - (int)ft_strlen(s)))
//             res[i++] = c;
//         res[i++] = s[j++];
//     }
//     res[i] = '\0';
//     return (res);
// }

// char *s_prec(char *s, char *size)
// {
//     char *res;
//     int siz;

//     siz = ft_atoi(size);
//     res = (char *)malloc(sizeof(char) * siz + 1);
//     if (s && (int)ft_strlen(s) > siz)
//     {
//         res = ft_strncpy(res, s, siz);
//         res[siz] = '\0';
//     }
//     //printf("%s\n", res);
//     return (res);
// }
// char *d_rev_width(char *s, char *size)
// {
//     char *res;

//     res = d_width(s, size, ' ');
//     res = ft_strrev(res);
// }

char *d_plus(t_data  *f)
{
    int len;
    int i;
    int j;

    i = 0;
    j = 0;
    len = (int)ft_strlen(f->output);
    if (!(f->result = (char *)malloc(sizeof(char) * len + 2)))
        return NULL;
    (atoi(f->output) > 0 && f->output[0] == '+') ? j++ : 0;
    (atoi(f->output) > 0 ) ? f->result[i++] = '+' : 0;
    while (len--)
        f->result[i++] = f->output[j++];
    f->result[i] = '\0';
    //   free(f->output);
    //   f->output = NULL;
    return (f->result);
}

int d_treat(t_data  *f)
{
    int i;

    i = 0;
    if (ft_strlen(f->flag)){
        while (f->flag[i])
        {
            if (f->flag[i++] == '+')
                d_plus(f);
        }
    }
        
printf("f->output - %s f->result - %s \n", f->output, f->result);
    return 1;
}

int print_res(t_data *f)
{
    if (f->type == 'd' && d_treat(f))
        ft_putstr(f->result);
    return 1;
}