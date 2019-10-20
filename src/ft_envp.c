/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:11:24 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/17 22:53:11 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int                 ft_new_node(t_nod **nd)
{
	*nd = (t_nod *)malloc(sizeof(t_nod));
	(*nd)->next = NULL;
	return (0);
}

t_nod	*ft_envdata(char **envp)
{
	int i;
	t_nod	*nd;
	t_nod	*head;

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
