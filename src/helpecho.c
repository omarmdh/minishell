/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpecho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:15:24 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/05 18:49:02 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    ft_puts(char *str, char c, char *str2)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putstr(str2);
}

int     ft_erro(int p)
{
	if (p == 1)
		ft_puts("Unmatched ", 34, ".\n");
	if (p == 2)
		ft_puts("Unmatched ", 39, ".\n");
	return (0);
}

int     ft_quote1(char   **arg)
{
	int i;
	int j;
	int q;

	q = 0;
	j = 0;
	while (arg[j])
	{
		i = 0;
		while (arg[j][i])
		{
			if (arg[j][i] == 39)
				q++;
			i++;
		}
		j++;
	}
	return (q);
}

int     ft_quote2(char   **arg)
{
	int i;
	int j;
	int q;

	q = 0;
	j = 0;
	while (arg[j])
	{
		i = 0;
		while (arg[j][i])
		{
			if (arg[j][i] == 34)
				q++;
			i++;
		}
		j++;
	}
	return (q);
}

char	*ft_copy(char *str, int size)
{
	int i;
	char *s;
	int j;

	i = 0;
	j = 0;
	s = ft_strnew(ft_strlen(str) - size);
	while (str[i])
	{
		if (str[i] != 39 && str[i] != 34)
		{
			s[j] = str[i];
			j++;
		}
		i++;
	}
	return (s);
}

int		ft_count_quotes(char *arg)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (arg[++i])
		(count == 39 || count == 34) ? count++ : 0 ;
	return (count);
}

int ft_checkdolar(char *str)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (str[i])
	{
		if (str[i] == '$')
			d++;
		i++;
	}
	return (d);
}

int		ft_dolar(char *arg, t_nod *env)
{
	t_nod *head;
	char **tab;
	int i;
	int	oneorzero;

	tab = ft_strsplit(arg, '$');
	i = 0;
	oneorzero = 0;
	head = env;
	while (tab[i])
	{
		env = head;
		while (env)
		{
			if (ft_strcmp(tab[i], env->data) == 0 && (oneorzero = 1))
				ft_putstr(env->value);
			env = env->next;
		}
		i++;
	}
	ft_free_tab(tab);
	return (oneorzero);
}

int		ft_mouvequotes(char **args, int ac, t_nod *env, char *home)
{
	char **tab;
	int i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * ac);
	while (args[i])
	{
		tab[i] = ft_copy(args[i], ft_count_quotes(args[i]));
		if (ft_dolar(tab[i], env) == 0 && ft_checkdolar(tab[i]) == 0)
		{
			if (tab[i][0] == '~' && tab[i][1] == '\0')
				ft_putstr(home);
			else
				ft_putstr(tab[i]);
			if (tab[i] != NULL)
				ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
	tab[i] = NULL;
	ft_free_tab(tab);
	return (0);
}

int echoo(char **av, t_nod *env)
{
	int ac;
	t_nod	*head;

	head = env;
	if ((ft_quote2(&av[1]) % 2) != 0 && ft_erro(1) == 0)
		return (1);
	if ((ft_quote1(&av[1]) % 2) != 0 && ft_erro(2) == 0)
		return (1);
	ac = 0;
	while (av[ac])
		ac++;
	while (env)
	{
		if (ft_strcmp(env->data, "HOME") == 0)
			break;
		env = env->next;
	}
	ft_mouvequotes(&av[1], ac, head, env->value);
	return (0);
}
