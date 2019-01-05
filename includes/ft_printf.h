#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include <stdarg.h>

// typedef struct 	s_data
// {
// 	char *data;
// 	char min;
// 	char plus;
// 	char flag;
// 	char type;
// }				t_data;

typedef struct 	d_fill
{
	char *zero_prec;
	char *space_width;
	char *znak;
}				t_fill;

typedef struct 	s_data
{
	char *data;
    char *flag;
    char *width;
    char *prec;
    char *spec;
	char type;
	char *output;
	char *result;
	int memory;
	t_fill dfill;
}				t_data;

void obnull_dfill(t_data  *f);
void empty_struct(t_data *f);


int		ft_printf(const char *format, ...);
int     check_data(const char *s, int *cnt_i, t_data *f);
int check_type(char c, t_data *f);
int check_flags(char c);
//void    def_type(va_list listPointer, char *s);
//void    def_type(va_list listPointer, char *s, t_data *i);
void	def_all(t_data *f);
void    def_type(va_list list, t_data *i);
int		print_res(t_data *f);



//обработка 
int d_treat(t_data  *f);
#endif