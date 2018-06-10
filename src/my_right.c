/*
** EPITECH PROJECT, 2017
** right
** File description:
** right
*/

#include "myls.h"
#include "my.h"

void    my_right(struct stat sb)
{
	my_printf(S_ISDIR(sb.st_mode) ? "d" : "-");
	my_printf(sb.st_mode & S_IRUSR ? "r" : "-");
	my_printf(sb.st_mode & S_IWUSR ? "w" : "-");
	my_printf(sb.st_mode & S_IXUSR ? "x" : "-");
	my_printf(sb.st_mode & S_IRGRP ? "r" : "-");
	my_printf(sb.st_mode & S_IWGRP ? "w" : "-");
	if ((sb.st_mode & S_ISGID) && !(sb.st_mode & S_IXGRP))
		my_printf("S");
	else if ((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
		my_printf("s");
	else
		my_printf((sb.st_mode & S_IXGRP) ? ("x") : ("-"));
	my_printf(sb.st_mode & S_IROTH ? "r" : "-");
	my_printf(sb.st_mode & S_IWOTH ? "w" : "-");
	if ((sb.st_mode & S_ISVTX) && !(sb.st_mode & S_IXOTH))
		my_printf("T ");
	else if ((sb.st_mode & S_ISVTX) && (sb.st_mode & S_IXOTH))
		my_printf("t ");
	else
		my_printf((sb.st_mode & S_IXOTH) ? ("x ") : ("- "));
}
