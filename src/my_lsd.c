/*
** EPITECH PROJECT, 2017
** ls
** File description:
** d
*/

#include "my.h"
#include "myls.h"

void	my_lsd(char *directory)
{
	struct stat sb;
	struct passwd *passwd;
	struct group *grp;

	stat(directory, &sb);
	passwd = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
	my_right(sb);
	my_printf("%d %s ", sb.st_nlink, passwd->pw_name);
	my_printf("%s %d ", grp->gr_name, sb.st_size);
	write(1, (ctime(&sb.st_mtime) + 4),
		(my_strlen(ctime(&sb.st_mtime)) - 13));
	my_printf(" %s", directory);
}
