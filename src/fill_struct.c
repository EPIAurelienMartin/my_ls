/*
** EPITECH PROJECT, 2017
** filml
** File description:
** strict
*/

#include "myls.h"
#include "my.h"

void    fill_folder(char *str, struct s_myls *ls)
{
	static int      nb = 0;

	ls->folder[nb] = my_strdup(str);
	nb += 1;
	ls->folder[nb] = NULL;
}

void    init_struct(struct s_myls *ls)
{
	ls->lr = 0;
	ls->rr = 0;
	ls->ld = 0;
	ls->l_r = 0;
	ls->lt = 0;
	ls->cpt = 0;
	ls->folder = my_str_to_word_array("." , "\n");
}

void    fill_option(char *str, struct s_myls *ls)
{
	int     i = 0;

	if (str[i] == '-')
		i++;
	if (str[i] != 'l' && str[i] != 'r' && str[i] != 'd' &&
		str[i] != 'R' && str[i] != 't') {
		my_printf("my_ls: invalid option -- '%c'", str[i]);
		my_putstr("\nTry './my_ls --help' for more information.");
		exit(84);
	}
	while (str[i]) {
		str[i] == 'l' ? ls->lr = 1 : 0;
		str[i] == 'r' ? ls->rr = 1 : 0;
		str[i] == 'd' ? ls->ld = 1 : 0;
		str[i] == 'R' ? ls->l_r = 1 : 0;
		str[i] == 't' ? ls->lt = 1 : 0;
		i += 1;
	}
}

void    fill_struct(int ac, char **av, struct s_myls *ls)
{
	int     i = 1;

	if (i == ac)
		return;
	while (i < ac) {
		if (my_strcmp(av[i], "--help") == 0)
			my_panel();
		else if (av[i][0] == '-')
			fill_option(av[i], ls);
		else
			fill_folder(av[i], ls);
		i++;
	}
}
