/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:07:57 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/20 14:32:34 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		handler(int sig)
{
	return (sig + 1);
}

void handle_sigint(int sig) 
{ 
	kill(111, sig);
} 

int		ft_if_fun(int ac, char **tab, t_nod **nd, char **envp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (envp[j] && ft_strncmp(envp[j], "HOME", 4) != 0)
		j++;
	(ft_strcmp(tab[0], "echo") == 0 && ft_echo(tab, *nd) == 1) ? i++ : 0;
	(ft_strcmp(tab[0], "unsetenv") == 0 && ft_unsetenv(nd, tab) == 1) ? i++ : 0;
	(ft_strcmp(tab[0], "cd") == 0 && ft_cd(ac, tab, envp[j]) == 0) ? i++ : 0;
	(ft_strcmp(tab[0], "setenv") == 0 && ft_setenv(nd, tab) == 0) ? i++ : 0;
	(ft_strcmp(tab[0], "env") == 0 && ft_env(nd) == 0) ? i++ : 0;
	return (i);
}

int		ft_commands(int ac, char *buff, char **envp, t_nod **nd)
{
	char **tab;
	char *cmd;

	signal(SIGINT, handle_sigint);
	if (buff[0] != '\0')
	{
		tab = ft_strsplit(buff, ' ');
		if (ft_if_fun(ac, tab, nd, envp) != 0)
		{
		//	ft_free_tab(tab);
			return (0);
		}
		if (fork() != 0)
			wait(NULL);
		else
		{
			if ((cmd = ft_joinpath(envp, tab[0])) == NULL)
			{
				free(cmd);
				ft_put4str("minishell", ": command not found: ", tab[0], "\n");
				ft_free_tab(tab);
				exit(0);
			}
			if (cmd != NULL)
				execve(cmd, tab, envp);
			free(cmd);
			ft_free_tab(tab);
			exit(0);
		}
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	char buff[B_SIZE];
	t_nod	*nd;
	int		ij[2];
	char	**commands;

	nd = ft_envdata(envp);
	av[1] = NULL;
	while(1)
	{
		(buff[0] != '\0') ? ft_clear(buff, commands) : 0 ;
		ij[0] = 0;
		ij[1] = 0;
		ft_put4str("\033[1;33m⚛️  ", /*ft_strrchr(getcwd(buff, B_SIZE), '/')*/ "シェルです", " $> ", "\033[0m");
		ft_strclr(buff);
		(read(0, buff, B_SIZE + 1) != -1) ? buff[ft_strlen(buff) - 1] = '\0' : 0;
		commands = ft_strsplit(buff, ';');
		if (buff[0] == '\0')
			continue ;
		(ft_strcmp("exit", commands[ij[0]]) == 0) ? ft_free_exit(commands, &nd) : 0;
		while (commands[ij[0]])
		{
			while (commands[ij[0]][ij[1]] == ' ' && commands[ij[0]][ij[1]])
				ij[1]++;
			ft_commands(ac, &commands[ij[0]][ij[1]], envp, &nd);
			ij[0]++;
		}
	}
	return (0);
}
