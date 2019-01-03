
#include "ft_printf.h"

char *d_width(t_data  *f, char c) // 33, 5, 0 00033
{
    char *res;
    int len;
    int i;
    int j;
    int min;

    min = 0;
    j = 0;
    i = 0;
   // len = 0;
   // if ((len = 0) && ((int)ft_strlen(f->result) > ft_atoi(f->width)))
        len = (int)ft_strlen(f->result);
    if ((int)ft_strlen(f->result) <= ft_atoi(f->width))
        len = ft_atoi(f->width);
    if (!(res = (char *)malloc(sizeof(char) * len + 1)))
        return NULL;
    (f->output[0] == '-' && ft_strchr(f->flag, '0')) ? (res[i++] = f->result[j++]) && (min++) : 0;
    while (len--)
    {
        while (i < (ft_atoi(f->width) - (int)ft_strlen(f->result)  + min))
            res[i++] = c;
        res[i++] = f->result[j++];
    }
   res[i] = '\0';
   return (res);
   //printf("len = %d f->width - %s -- %d\n", len, f->result, ft_atoi(f->width));

}

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
char	*ft_srev_pos(char *str, int position)
{
	int		len;
	int		j;
	int		i;
	char	temp;
  
  i = (position || 0);
	len = ft_strlen(str);
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
	return (str);
}

char *d_r_width(t_data  *f, char c) // 33, 5, 0 00033
{
    char *res;
    int len;
    int i;
    int j;
    int cnt_i; 

    j = 0;
    i = 0;
    if ((len = 0) && ((int)ft_strlen(f->result) > ft_atoi(f->width)))
        len = (int)ft_strlen(f->result);
    if ((int)ft_strlen(f->result) <= ft_atoi(f->width))
        len = ft_atoi(f->width);
    if (!(res = (char *)malloc(sizeof(char) * len + 1)))
        return NULL;
    cnt_i = len - (int)ft_strlen(f->result);
    while (len-- - cnt_i > 0)
        res[i++] = f->result[j++];
    while (cnt_i-- > 0)
          res[i++] = c;
   res[i] = '\0';
   return (res);
}


char *d_rev_width(t_data  *f)
{
  char *res;
 // int s;

 //   (f->output[0] == '-') ? (s = 1) : (s = 0);
  res = d_r_width(f, ' ');
  //res = ft_srev_pos(res, s);
  return res;
}

char *d_minus_width(t_data  *f, char c)
{
  char *res;
  int s;

    (f->output[0] == '-') ? (s = 1) : (s = 0);
  res = d_width(f, c);
  return res;
}

char *d_plus(t_data  *f)
{
static int fl = 1; //
    int len;
    int i;
    int j;


    i = 0;
    j = 0;
    len = (int)ft_strlen(f->output);
    if (fl)
    {
        if (!(f->result = (char *)malloc(sizeof(char) * len + 2)))
            return NULL;
        (atoi(f->output) > 0 && f->output[0] == '+') ? j++ : 0;
        (atoi(f->output) > 0 && fl--) ? f->result[i++] = '+' : 0;
        while (len--)
            f->result[i++] = f->output[j++];
        f->result[i] = '\0';
        //   free(f->output);
        //   f->output = NULL;
    }
    return (f->result);
}

int d_treat(t_data  *f)
{
    int i;
    //char *leak;

    i = 0;
    f->result = f->output;
    if (ft_strlen(f->flag)){
        while (f->flag[i])
        {
            if (f->flag[i] == '+')
            {
                d_plus(f);

            } 
            if (f->flag[i] == '0')
            {
                if (ft_atoi(f->output) < 0) 
                     f->result = d_minus_width(f, '0'); 
                 else
                    f->result = d_width(f, '0'); // leak
            }
            if (f->flag[i] == '-')
            {
                f->result = d_rev_width(f);
            }
            i++;
        }
    }
    if (ft_strlen(f->width) && !ft_strlen(f->flag))
    {
        f->result = d_width(f, ' ');
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