/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:05:58 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/11 14:31:34 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		expose_hook(t_env *e)
{
	int	i;

	i = 0;
	if (e->f == 0)
	{
		e->img_map = mlx_new_image(e->ptr, e->win_x, e->win_y);
		e->data_map = (int *)mlx_get_data_addr(e->img_map, &i, &i, &i);
		get_grid(e);
		e->f = e->f + 1;
	}
	e->img = e->img_map;
	e->data = e->data_map;
	get_perso(e, e->pe);
	write(1, "x = ", 4);
	ft_putnbr(e->pe->mv_y);
	write(1, " y = ", 5);
	ft_putnbr(e->pe->pos_y);
	write(1, " r = ", 5);
	ft_putnbr(e->pe->angle);
	write(1, "°\n", 4);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	erase_player(e, e->pe->y_map, e->pe->x_map);
	return (i);
}
