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

typedef struct 	s_data
{
	char *data;
    char *flag;
    char *width;
    char *prec;
    char *spec;
	char type;
	//va_list     list;
	// char *data;
	// char type;
	// char spec;
	// char min;
	// char plus;
	// char spc;
	// char hash;
	// char zero;
	// char precision;
	// int width;
}				t_data;

int		ft_printf(const char *format, ...);
int     check_data(const char *s, int *cnt_i, t_data *f);
int check_type(char c, t_data *f);
int check_flags(char c);
//void    def_type(va_list listPointer, char *s);
//void    def_type(va_list listPointer, char *s, t_data *i);
void    def_type(va_list listPointer, t_data *i);
void	def_all(t_data *f);
#endif