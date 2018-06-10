/*
** EPITECH PROJECT, 2017
** ls
** File description:
** my
*/

#ifndef _MYLS_H_
#define _MYLS_H_

#define ERROR 84
#define SUCESS 0

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

struct s_myls
{
	int	lr;
	int	rr;
	int	ld;
	int	l_r;
	int	lt;
	int	cpt;
	char	*path;
	char	**folder;
};

void	fill_folder(char *str, struct s_myls *l);
void	init_struct(struct s_myls *l);
void	fill_option(char *str, struct s_myls *l);
void	fill_path(struct s_myls *l, char **env);
void	fill_struct(int ac, char **av, struct s_myls *l);
void	my_panel(void);
void	my_right(struct stat sb);
char	*file_to_inspect(char *ls, char *file);
void	disp_total_block(char *rep);
void	my_ls_l(DIR *dir, char *tot);
void	my_simple_ls(DIR *dir);
void	my_ls_rmaj(struct s_myls *ls, char *directory);
void	my_ls_lrmaj(struct s_myls *ls, char *directory);
void	check_for_jump(struct s_myls *ls, int i);
void	my_ls_t(struct s_myls *ls, DIR *dir, char *directory);
void	my_option(struct s_myls *ls, DIR *dir);
void	start_ls(struct s_myls *ls);
void	my_ls_t(struct s_myls *ls, DIR *dir, char *directory);
void	my_lsd(char *directory);
void	my_ls_rmin(char *directory);

#endif
