
#include "ft_printf.h"

void create_width(char **width, char *s, int *i)
{
  int cnt;
  //int arg;

  cnt = 0;
  if (s[cnt] == '*')
  {
    //arg = va_arg(listPoint, int);
    //*width = ft_strsub(ft_itoa(arg), 0, ft_strlen(arg));
  }
  else if (s[cnt])
  {
    while (s[cnt] >= 48 && s[cnt] <= 57)
    {
      cnt++;
      (*i)++;
    }
    *width = ft_strsub(s, 0, cnt--);
  }
}
void create_prec(char **prec, char *s, int *i)
{
  int cnt; 
  char *str;

  (*i)++;
  cnt = 1;
  //if (s[cnt] == '*')
//    ss = ft_itoa(vaarg(list, int))
//  else 
  if (s[cnt] >= 48 && s[cnt] <= 57)
  {
	    str = s;
  		while (str[cnt] && str[cnt] >= 48 && str[cnt] <= 57)
		{
			cnt++;
			(*i)++; 
		}
  		cnt--;
  		*prec = ft_strsub(s, 1, cnt--);
  }
}

int check_size(char **size, char *s, int *i)
{
	int cnt; 

	cnt = 0;
	if ((s[cnt] == 'l' || s[cnt] == 'h') && check_type(s[cnt + 1], NULL))
	{
		*size = ft_strsub(s, 0, 1);
		(*i)++;
	}
	else if ((ft_strnequ(s, "ll", 2) ||
		ft_strnequ(s, "hh", 2)) && check_type(s[cnt + 2], NULL))
	{
		*size = ft_strsub(s, 0, 2);
		(*i) += 2;
	}
	else
		return 0;
	return 1;
	
}

void def_all(t_data *f)
{
    int step;
    int i;

    i = 0;
    step = 0;
    while (++step <= 4)
    {
        if (step == 1)
        {
            while (check_flags(f->data[i]))
                i++;
            f->flag = ft_strsub(f->data, 0, i--);
			step++;
        }
        if (step == 2)
    	{
            //i++;
            if ((f->data[++i] >= 49 && f->data[i] <= 57) || f->data[i] == '*')
                create_width(&f->width, f->data + i, &i);
			step++;
        }
		if (step == 3)
		{
			if (f->data[i] == '.')
				create_prec(&f->prec, f->data + i, &i);
			step++;
		}
		if (step == 4)
      	 	(check_size(&f->spec, f->data + i, &i)) ? step++ : step++;
	}
}