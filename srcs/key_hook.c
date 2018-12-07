/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:46 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/07 16:15:58 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int	key_press(int k, t_env *e)
{
//	write(1, ".", 1);
	if (k == W)
		e->pe->mv_y = 1;
	if (k == S)
		e->pe->mv_y = -1;
	if (k == D)
		e->pe->mv_x = 1;
	if (k == A)
		e->pe->mv_x = -1;
//	write(1, ".\n", 2);
	expose_hook(e);
	return (0);
}

int	key_release(int k, t_env *e)
{
//	write(1, "-", 1);
	if (k == W || k == S)
		e->pe->mv_y = 0;
	if (k == D || k == A)
		e->pe->mv_x = 0;
	expose_hook(e);
//	write(1, "-\n", 2);
	return (0);
}
