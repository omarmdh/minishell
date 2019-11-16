/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:07:57 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/16 13:07:59 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/libft.h"

int		ft_oldpwd(t_nod **n)
{
	t_nod *nd;
	char	buff[B_SIZE];

	nd = *n;
	getcwd(buff, B_SIZE);
	if (!buff[0])
		return (0);
	while (nd)
	{
		if (ft_strcmp(nd->data, "OLDPWD") == 0)
		{
			free(nd->value);
			nd->value = ft_strdup(buff);
		}
		nd = nd->next;
	}
	return (0);
}

char	**ft_path(t_nod **n)
{
	char **path;
	t_nod *nd;
	char *pwd;
	char buff[B_SIZE];

	pwd = getcwd(buff, B_SIZE);
	if (!buff[0])
		return (NULL);
	nd = *n;
	path = (char**)malloc(sizeof(char*) * 3);
	path[2] = NULL;
	while (nd)
	{
		if (ft_strcmp(nd->data, "HOME") == 0)
			path[1] = ft_strdup(nd->value);
		if (ft_strcmp(nd->data, "OLDPWD") == 0)
			path[0] = ft_strdup(nd->value);
		if (ft_strcmp(nd->data, "PWD") == 0)
		{
			free(nd->value);
			nd->value = ft_strdup(pwd);
		}
		nd = nd->next;
	}
	return (path);
}

void	ft_print_p(void)
{
	char buff[B_SIZE];

	getcwd(buff, B_SIZE);
	if (!buff[0])
	{
		ft_putstr("$>");
		return ;
	}
	if (ft_git(buff) != 1)
		ft_put4str("\033[1;33m", ft_strrchr(buff, '/'), " $> ", "\033[0m");
	else
	{
		ft_put4str("\033[1;33m", ft_strrchr(buff, '/'), "\033[34;1m git:(", "\033[0m");
		ft_put4str("\033[31;1mmaster\033[34;1m)", "\033[1;33m $> \033[0m", "", "");
	}
	ft_strclr(buff);
}

void	ft_ctrl_c(int sig)
{
	ft_putchar('\n');
	ft_print_p();
	ret = sig;
}

int				ft_commands(char *buff, char **envp, t_nod **nd, char **path)
{
	char		**tab;
	char		*cmd;
	char		*tmp;

	ret = 1;
	if (buff[0] != '\0')
	{
		if (!(tab = ft_spl_whitespaces(buff)))
			return (0);
		if (ft_strcmp("exit", tab[0]) == 0)
		{
			ft_free_tab(tab);
			return (1);
		}
		if (tab[0][0] == '$')
			if (ft_dol_fun(*nd, &tab[0]) == 0)
			{
				ft_put4str(&tab[0][1], ": Undefined variable.", "", "\n");
				ft_free_tab(tab);
				return (0);
			}
		if (ft_if_fun(tab, nd, envp, path) != 0)
			return (0);
		if (fork() != 0)
			wait(NULL);
		else
		{
			if ((cmd = ft_joinpath(envp, tab[0])) == NULL)
				ft_error(tab, cmd);
			execve(cmd, tab, envp);
		}
		ft_free_tab(tab);
		//		ft_strdel(&cmd);
	}
	return (0);
}

void			mainhelper(char ***cmd_path_env, char *buff, t_nod	**nd)
{
	cmd_path_env[1] = ft_path(nd);
	cmd_path_env[2] =  ft_tabenv(nd);
	(buff[0] != '\0') ? ft_clear(buff, cmd_path_env[0]) : 0 ;
	(ret == 2) ? (ret = 1) : ft_print_p();
	(read(0, buff, B_SIZE + 1)) != -1 ? buff[ft_strlen(buff) - 1] = '\0' : 0;
	cmd_path_env[0] = ft_strsplit(buff, ';');
}

int				main(int ac, char **av, char **envp)
{
	char		buff[B_SIZE];
	t_nod		*nd;
	int			ij[2];
	char		**cmd_path_env[3];

	if (!*envp)
		(ft_putstr("Minishell: Environnement Not Found !!!\n")) ? 0 : exit(0);
	signal(SIGINT, ft_ctrl_c);
	nd = ft_envdata(envp, ac, av);
	while (1)
	{
		ij[0] = -1;
		ij[1] = 0;
		mainhelper(cmd_path_env, buff, &nd);
	/*	cmd_path_env[1] = ft_path(&nd);
		cmd_path_env[2] =  ft_tabenv(&nd);
		(buff[0] != '\0') ? ft_clear(buff, cmd_path_env[0]) : 0 ;
		(ret == 2) ? (ret = 1) : ft_print_p();
		(read(0, buff, B_SIZE + 1)) != -1 ? buff[ft_strlen(buff) - 1] = '\0' : 0;
		cmd_path_env[0] = ft_strsplit(buff, ';');*/
		if ((buff[0] == '\0' || cmd_path_env[0][0] == NULL) && (ret = 1))
			continue ;
		while (cmd_path_env[0][++ij[0]])
			if (ft_commands(cmd_path_env[0][ij[0]], cmd_path_env[2], &nd, cmd_path_env[1]) == 1)
				ij[1] = 6;
		if (ij[1] == 6)
			break;
		ft_destroy_all(&cmd_path_env[0], &cmd_path_env[1], &cmd_path_env[2], buff);
	}
	ft_destroy_all(&cmd_path_env[0], &cmd_path_env[1], &cmd_path_env[2], buff);
	ft_freelist(&nd);
	return (0);
}
