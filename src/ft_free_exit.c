/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:08:45 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/19 16:58:19 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clear(char *buff, char **tab)
{
	ft_strclr(buff);
	ft_free_tab(tab);
}

void    ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_freelist(t_nod **n)
{
	t_nod *nd;
	t_nod *tmp;

	nd = *n;
	while (nd)
	{
		tmp = nd->next;
		ft_strdel(&nd->data);
		ft_strdel(&nd->value);
		free(nd);
		nd = tmp;
	}
}

void	ft_free_exit(char **tab, t_nod **nd)
{
	ft_freelist(nd);
	ft_free_tab(tab);
	exit(0);
}
