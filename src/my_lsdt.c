/*
** EPITECH PROJECT, 2017
** ls
** File description:
** dandt
*/

#include "myls.h"
#include "my.h"

long     my_put_long(long nb)
{
	long i = 0;

	if (nb >= 10) {
		i += my_put_nbr(nb / 10);
		i +=  my_putchar(48 + nb % 10);
	} else
		i += my_putchar(48 + nb);
	return (i);
}

char    **swap_elem(int index1, int index2, char **tab)
{
	char	*tmp = my_strdup(tab[index1]);

	tab[index1] = my_strdup(tab[index2]);
	tab[index2] = my_strdup(tmp);
	free(tmp);
	return (tab);
}

char	**compare_time(char **tab, char *directory)
{
	int	y = 0;
	char	*str = NULL;
	char	*str2 = NULL;
	long	tmp = 0;
	struct stat sb;

	while (tab[y + 1]) {
		str = file_to_inspect(directory, tab[y]);
		str2 = file_to_inspect(directory, tab[y + 1]);
		stat(str, &sb);
		tmp = sb.st_mtime;
		stat(str2, &sb);
		if (tmp < sb.st_mtime) {
			swap_elem(y, y + 1, tab);
			y = 0;
			continue;
		} else
			y++;
	}
	return (tab);
}

void    my_ls_t(struct s_myls *ls, DIR *dir, char *directory)
{
	(void)ls;
	struct dirent *dirent;
	char	**tab;
	char	*names = "\0";

	while ((dirent = readdir(dir)) != 0) {
		if ((dirent->d_name[0] != '.')) {
			names = my_strcat(names, dirent->d_name);
			names = my_strcat(names, "\n");
		}
	}
	tab = my_str_to_word_array(names, "\n");
	tab = compare_time(tab, directory);
	my_show_word_array(tab);
}
