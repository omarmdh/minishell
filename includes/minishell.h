/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:26:46 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/16 13:07:22 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
# include <dirent.h>
#include "../libft/libft.h"

#define B_SIZE 4096

int				ret;

typedef struct  s_nod
{
	char    *data;
	char	*value;
	struct  s_nod *next;
}               t_nod;

void    ft_destroy_all(char ***tab, char ***tab1, char ***tab2, char *buff);
int		ft_dol_fun(t_nod    *env, char **cmd);
int     ft_check_excist(char *rpath);
int		echoo(char **av, t_nod *env);
int     ft_skipspaces(char ***commands);
int		ft_if_fun(char **tab, t_nod **nd, char **envp, char **path);
int     ft_oldpwd(t_nod **n);
int 	ft_git(char *path);
char    **ft_tabenv(t_nod   **n);
void	ft_freelist(t_nod **nd);
void	ft_free_cmd_tab(char *cmd, char **tab);
void    ft_error(char **tab, char *cmd);
void	ft_clear(char *buff, char **tab);
void    ft_free_exit(char **tab, char **tab1, t_nod **nd);
void    ft_free_tab(char **tab);
int		ft_unsetenv(t_nod **n, char **tab);
int     ft_lent(char *str, char c);
int   	ft_setenv(t_nod **nd, char **tab);
void    ft_addenv(t_nod **nd, char **tab);
int		ft_new_node(t_nod **nd);
t_nod   *ft_envdata(char **envp, int ac, char **av);
int		ft_cd(char **av, char **home, t_nod **nd);
int     ft_env(t_nod **nd);
int     ft_check_excist(char *rpath);
int     ft_echo(char **av, t_nod *nd);
char    *check_path(char **envp);
char    *ft_joinpath(char **envp, char *cmd);

#endif
