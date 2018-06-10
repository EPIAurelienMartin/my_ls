/*
** EPITECH PROJECT, 2017
** ls
** File description:
** tiretr
*/

#include "myls.h"
#include "my.h"

void    my_simple_ls(DIR *dir)
{
	struct dirent *dirent;

	while ((dirent = readdir(dir)) != 0) {
		if ((dirent->d_name[0] != '.'))
			my_printf("%s\n", dirent->d_name);
	}
}

void    my_ls_rmaj(struct s_myls *ls, char *directory)
{
	struct dirent *dirent;
	struct stat   sb;
	DIR     *dir;
	char *str;

	my_simple_ls(opendir(directory));
	my_putchar('\n');
	dir = opendir(directory);
	while ((dirent = readdir(dir)) != 0) {
		str = my_strcat(my_strcat(directory, "/"), dirent->d_name);
		stat(str, &sb);
		if (S_ISDIR(sb.st_mode) && dirent->d_name[0] != '.') {
			my_printf("%s:\n", str);
			my_ls_rmaj(ls, str);
		}
	}
}

void    my_ls_lrmaj(struct s_myls *ls, char *directory)
{
	struct dirent *dirent;
	struct stat   sb;
	DIR     *dir;
	char *str;

	my_ls_l(opendir(directory), directory);
	my_putchar('\n');
	dir = opendir(directory);
	while ((dirent = readdir(dir)) != 0) {
		str = my_strcat(my_strcat(directory, "/"), dirent->d_name);
		stat(str, &sb);
		if (S_ISDIR(sb.st_mode) && dirent->d_name[0] != '.') {
			my_printf("%s:\n", str);
			my_ls_lrmaj(ls, str);
		}
	}
}
