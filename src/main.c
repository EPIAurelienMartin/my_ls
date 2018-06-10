/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "myls.h"
#include "my.h"

void	my_panel(void)
{
	my_printf("Usage: ls -[OPTION]... [FILE]...\n");
	my_printf("Option are : \n");
	my_printf("\tl : Long listing format\n");
	my_printf("\tr : reverse order while sorting\n");
	my_printf("\td : list directories themselves, not their contents\n");
	my_printf("\tR : list subdirectories recursively\n");
	my_printf("\tt : sort by modification time, newest first\n");
	exit(SUCESS);
}

void	check_all_folder(char **folder)
{
	DIR	*dir;
	int	i = 0;

	while (folder[i]) {
		if ((dir = opendir(folder[i])) == NULL) {
			my_printf("my_ls: cannot acces '%s'", folder[i]);
			my_putstr(": No such file or directory\n");
		}
		closedir(dir);
		i++;
	}
}

int	main(int ac, char **av)
{
	struct s_myls ls;

	if (ac == 1) {
		my_simple_ls(opendir("./"));
		return (SUCESS);
	}
	init_struct(&ls);
	fill_struct(ac, av, &ls);
	check_all_folder(ls.folder);
	start_ls(&ls);
	return (SUCESS);
}
