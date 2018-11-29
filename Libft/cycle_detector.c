/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:41:20 by exam              #+#    #+#             */
/*   Updated: 2018/10/10 11:28:42 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			detect(const t_list *list, t_list *c)
{
	t_list *tmp;

	if (!c || !c->next)
		return (0);
	if (c->next == list || c->next == c)
		return (1);
	tmp = list->next;
	while (tmp && tmp != c)
	{
		if (c->next == tmp)
			return (1);
		tmp = tmp -> next;
	}
	return (0);
}

int			cycle_detector(const t_list *list)
{
	t_list	*tmp;

	if (!list || !list->next)
		return (0);
	tmp = list->next;
	while (tmp && !detect(list, tmp))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	return (1);
}

