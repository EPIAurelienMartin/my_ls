/*
** EPITECH PROJECT, 2017
** option
** File description:
** ls
*/

#include "myls.h"
#include "my.h"

void    check_for_jump(struct s_myls *ls, int i)
{
	if ((opendir(ls->folder[ls->cpt + i])) != NULL) {
		my_printf("\n");
		return;
	} else if ((opendir(ls->folder[ls->cpt + i])) == NULL) {
		i += 1;
		if (ls->folder[ls->cpt + i] != NULL)
			check_for_jump(ls, i);
	} else
		return;
}

void	my_multi_opt(struct s_myls *ls)
{
	if (ls->lr == 1 && ls->rr == 0 && ls->ld == 1 &&
		ls->l_r == 0 && ls->lt == 0) {
		my_lsd(ls->folder[ls->cpt]);
		if (!(ls->folder[ls->cpt + 1]))
			my_putchar('\n');
	}
	if (ls->lr == 1 && ls->rr == 0 && ls->ld == 0 &&
		ls->l_r == 1 && ls->lt == 0) {
		my_printf("%s:\n", ls->folder[ls->cpt]);
		my_ls_lrmaj(ls, ls->folder[ls->cpt]);
	}
}

void	my_simple_option(struct s_myls *ls)
{
	if (ls->lr == 0 && ls->rr == 0 && ls->ld == 0 &&
		ls->l_r == 1 && ls->lt == 0) {
		my_printf("%s:\n", ls->folder[ls->cpt]);
		my_ls_rmaj(ls, ls->folder[ls->cpt]);
	}
	if (ls->lr == 0 && ls->rr == 1 && ls->ld == 0 &&
		ls->l_r == 0 && ls->lt == 0) {
		my_ls_rmin(ls->folder[ls->cpt]);
	} else
		my_multi_opt(ls);
}

void    my_option(struct s_myls *ls, DIR *dir)
{
	if (ls->lr == 1 && ls->rr == 0 && ls->ld == 0 &&
		ls->l_r == 0 && ls->lt == 0) {
		my_ls_l(dir, ls->folder[ls->cpt]);
	}
	if (ls->lr == 0 && ls->rr == 0 && ls->ld == 0 &&
		ls->l_r == 0 && ls->lt == 1) {
		my_ls_t(ls, dir, ls->folder[ls->cpt]);
	}
	if (ls->lr == 0 && ls->rr == 0 && ls->ld == 1 &&
		ls->l_r == 0 && ls->lt == 0) {
		my_printf("%s", ls->folder[ls->cpt]);
		if (!(ls->folder[ls->cpt + 1]))
			my_putchar('\n');
	} else
		my_simple_option(ls);
}

void    start_ls(struct s_myls *ls)
{
	DIR   *dir;

	while (ls->folder[ls->cpt]) {
		if ((dir = opendir(ls->folder[ls->cpt])) == NULL) {
			ls->cpt++;
			continue;
		}
		if (ls->folder[1] && ls->ld != 1)
			my_printf("%s:\n", ls->folder[ls->cpt]);
		if (ls->lr == 0 && ls->rr == 0 && ls->ld == 0 &&
			ls->l_r == 0 && ls->lt == 0) {
			my_simple_ls(dir);
		} else
			my_option(ls, dir);
		if (ls->folder[ls->cpt + 1] != NULL)
			check_for_jump(ls, 1);
		closedir(dir);
		ls->cpt++;
	}
}
