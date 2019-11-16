/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:11:24 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/14 23:25:41 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_joinenv(t_nod *nd)
{
	char *env;
	char *ptr;

	ptr = ft_strjoin(nd->data, "=");
	env = ft_strjoin(ptr, nd->value);
	free(ptr);
	return (env);
}

int		ft_lentlist(t_nod **n)
{
	int i;
	t_nod	*nd;

	i = 0;
	nd = *n;
	while (nd)
	{
		nd = nd->next;
		i++;
	}
	return (i);
}

char	**ft_tabenv(t_nod	**n)
{
	int lent;
	int i;
	t_nod *nd;
	char	**tabenv;

	nd = *n;
	i = 0;
	lent = ft_lentlist(n) + 1;
	tabenv = (char**)malloc(sizeof(char*) * lent);
	while (nd)
	{
		tabenv[i] = ft_joinenv(nd);
		nd = nd->next;
		i++;
	}
	tabenv[i] = NULL;
	return (tabenv);
}

int                 ft_new_node(t_nod **nd)
{
	*nd = (t_nod *)malloc(sizeof(t_nod));
	(*nd)->next = NULL;
	return (0);
}	

t_nod	*ft_envdata(char **envp, int ac, char **av)
{
	int i;
	t_nod	*nd;
	t_nod	*head;

	av[ac - 1] = NULL;
	i = 0;
	ft_new_node(&nd);
	head = nd;
	while (envp[i])
	{
		size_t size;

		size = ft_lent(envp[i], '=');
		nd->data = ft_strndup(envp[i], size);
		nd->value = ft_strdup(&envp[i][ft_lent(envp[i], '=') + 1]);
		if (envp[i + 1] != NULL)
		{
			ft_new_node(&(nd->next));
			nd = nd->next;
		}
		i++;
	}
	return (head);
}

int 	ft_env(t_nod **nd)
{
	t_nod *head;

	head = *nd;
	while (*nd)
	{
		ft_put4str((*nd)->data, "=", (*nd)->value, "\n");
		(*nd) = (*nd)->next;
	}
	*nd = head;
	return (0);
}
