/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:23:02 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/19 17:52:35 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delnode(t_nod **nd)
{
	if (*nd != NULL)
	{
		free((*nd)->data);
		free((*nd)->value);
		free(*nd);
	}
}

int		ft_unsetenv(t_nod **n, char **tab)
{
	t_nod *nd;
	t_nod *head;
	t_nod *tmp;
	int		i;

	i = -1;
	nd = *n;
	head = *n;
	if (tab[1] == NULL)
		ft_putstr("unsetenv: Too few arguments.\n");
	while (tab[++i])
	{
		while (nd)
		{
			if (nd->next != NULL)
				tmp = nd->next;
			if (ft_strcmp(tab[i], tmp->data) == 0)
			{
				nd->next = tmp->next;
				ft_delnode(&tmp);
			}
			nd = nd->next;
		}
		nd = head;
	}
	return (1);
}

void	ft_free_add(t_nod *nd, char *tab)
{
	if (tab != NULL)
	{
		free(tab);
		nd->value = ft_strdup(tab);
		return ;
	}
	nd->value = ft_strdup(tab);
}

void	ft_addenv(t_nod **n, char **tab)
{
	t_nod	*nd;
	int 	i;

	i = 0;
	nd = *n;
	while (nd)
	{
		if (ft_strcmp(tab[1], nd->data) == 0 && tab[2] != NULL && (i = 1))
			ft_free_add(nd, tab[2]);
		if (ft_strcmp(tab[1], nd->data) == 0 && tab[2] == NULL && (i = 1))
			nd->value = ft_strnew(0);
		if (nd->next == NULL && i == 0)
		{
			ft_new_node(&nd->next);
			nd = nd->next;
			nd->data = ft_strdup(tab[1]);
			if (tab[2] != NULL)
				ft_free_add(nd, tab[2]);
			else
				nd->value = ft_strnew(0);
			break;
		}
		nd = nd->next;
	}
}

int ft_setenv(t_nod **nd, char **tab)
{
	int i;

	i = 0;
	if (tab[1] == NULL)
	{
		ft_env(nd);
		return (0);
	}
	if (tab[3] != NULL)
	{
		ft_putstr("setenv: Too many arguments.\n");
		return (0);
	}
	if (ft_isalpha(tab[1][0]) == 0)
	{
		ft_putstr("setenv: Variable name must begin with a letter.\n");
		return (0);
	}
	else
		ft_addenv(nd, tab);
	return (0);
}
