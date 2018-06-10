/*
** EPITECH PROJECT, 2017
** my
** File description:
** lsr
*/

#include "my.h"
#include "myls.h"

void	my_ls_rmin(char *directory)
{
	char	**tab = my_str_to_word_array("bonjour\n", "\n");
	struct dirent *dirent;
	int	y = 0;
	DIR *dir;

	dir = opendir(directory);
	while ((dirent = readdir(dir)) != 0) {
		if ((dirent->d_name[0] != '.')) {
			tab[y] = my_strdup(dirent->d_name);
			y += 1;
		}
	}
	y -= 1;
	while (y >= 0) {
		my_printf("%s\n", tab[y]);
		y--;
	}
}
