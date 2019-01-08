#include "ft_printf.h" 
 
void free_fill_mem(t_data  *f)
{
	(f->dfill.space_width) ? free(f->dfill.space_width) : 0;
	f->dfill.znak = "\0";
	(f->dfill.zero_prec) ? free(f->dfill.zero_prec) : 0;
}

void obnull_dfill(t_data  *f)
{
	f->dfill.znak = "\0";
	f->dfill.space_width = NULL;
	f->dfill.zero_prec = NULL;
}
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
    f->memory = 0;
	f->i_p = 0;
}
void free_all_mem(t_data  *f)
{
    (f->output && f->type == 's') ? f->output = NULL : free(f->output);	
	(f->data) ? free(f->data) : 0;
	(f->width) ? free(f->width) : 0;
	(f->spec) ? free(f->spec) : 0;
	(f->prec) ? free(f->prec) : 0;
	(f->flag) ? free(f->flag) : 0;
	(f->result) ? free(f->result) : 0;
	//(f->buff) ? free(f->buff) : 0 ;
    f->type = 0;
    f->memory = 0;
}