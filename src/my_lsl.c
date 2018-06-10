/*
** EPITECH PROJECT, 2017
** ls
** File description:
** tiretl
*/

#include "myls.h"
#include "my.h"

char    *file_to_inspect(char *ls, char *file)
{
	char    *str = my_strdup(ls);

	if (my_strcmp(str, ".") == 0) {
		str = my_strcat(str, "/");
		str = my_strcat(str, file);
		return (str);
	}
	str = my_strcat(str, "/");
	str = my_strcat(str, file);
	return (str);
}

void    disp_total_block(char *rep)
{
	struct stat     sb;
	struct dirent   *drt;
	int     tot = 0;
	char    *cat;
	DIR     *dir = opendir(rep);

	while ((drt = readdir(dir))) {
		cat = my_strcat(my_strcat(rep, "/"), drt->d_name);
		if ((lstat(cat, &sb)) == 0)
			(drt->d_name[0] != '.') ? tot += sb.st_blocks : 0;
	}
	closedir(dir);
	my_printf("total %d\n", tot / 2);
}

void    my_ls_l(DIR *dir, char *tot)
{
	struct dirent *dirent;
	struct stat   s;
	struct passwd *passwd;
	struct group  *grp;
	char *str;

	disp_total_block(tot);
	while ((dirent = readdir(dir)) != 0) {
		if ((dirent->d_name[0] != '.')) {
			str = file_to_inspect(tot, dirent->d_name);
			stat(str, &s);
			passwd = getpwuid(s.st_uid);
			grp = getgrgid(s.st_gid);
			my_right(s);
			my_printf("%d %s ", s.st_nlink, passwd->pw_name);
			my_printf("%s %d ", grp->gr_name, s.st_size);
			write(1, (ctime(&s.st_mtime) + 4), \
				(my_strlen(ctime(&s.st_mtime)) - 13));
			my_printf(" %s\n", dirent->d_name);
		}
	}
}
