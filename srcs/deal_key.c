/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:42:26 by apelissi          #+#    #+#             */
/*   Updated: 2018/11/29 18:26:34 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		deal_key(int key, t_env *te)
{
	if (key == W || key == UP)
		te->pe->pos_y--;
	if (key == S || key == DOWN)
		te->pe->pos_y++;
	if (key == A || key ==  LEFT)
		te->pe->pos_x--;
	if (key == D || key ==  RIGHT)
		te->pe->pos_x++;
	write(1, "x = ", 4);
	ft_putnbr(te->pe->pos_x);
	write(1, " y = ", 5);
	ft_putnbr(te->pe->pos_y);
	write(1, "\n", 1);
	return(0);
}
