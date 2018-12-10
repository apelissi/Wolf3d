/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:25:58 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/10 14:12:52 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	init(t_env *e)
{
	e->win_x = 500;
	e->win_y = 500;
	e->f = 0;
	e->pe->pos_x = 0;
	e->pe->pos_y = 0;
	e->pe->angle = 0;
	e->pe->mv_y = 0;
	e->pe->mv_x = 0;
	e->pe->mv_r = 0;
}

int		ft_mlx(t_env *e)
{
	init(e);
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, e->win_x, e->win_y, "TEST");
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	//	mlx_key_hook(e->win, deal_key, e);
	//	mlx_mouse_hook(e->win, deal_mouse, e);
	//	mlx_hook(e->win, 6, (1L << 6), mouse_move_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->ptr);
	return (0);
}
