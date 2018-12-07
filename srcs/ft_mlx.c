/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:25:58 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/07 17:01:41 by apelissi         ###   ########.fr       */
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
	e->pe->mv_y = 0;
	e->pe->mv_x = 0;
	e->pe->angle = 0;
}

int		expose_hook(t_env *e)
{
	int	i;

	i = 0;
	if (e->f == 0)
	{
		e->img_map = mlx_new_image(e->ptr, e->win_x, e->win_y);
		e->data_map = (int *)mlx_get_data_addr(e->img_map, &i, &i, &i);
		fill_img(e);
		e->f = e->f + 1;
	}
	e->img = e->img_map;
	e->data = e->data_map;
	e->pe->pos_x += e->pe->mv_x;
	e->pe->pos_y += e->pe->mv_y;
	write(1, "x = ", 4);
	ft_putnbr(e->pe->pos_x);
	write(1, " y = ", 5);
	ft_putnbr(e->pe->pos_y);
	write(1, "\n", 1);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
//	mlx_destroy_image(e->ptr, e->img);
	return (i);
}

int		ft_mlx(t_env *e)
{
	init(e);
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, e->win_x, e->win_y, "TEST");
	write(1, "0\n", 2);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	write(1, "1\n", 2);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	write(1, "2\n", 2);
	//	mlx_key_hook(e->win, deal_key, e);
	//	mlx_mouse_hook(e->win, deal_mouse, e);
	//	mlx_hook(e->win, 6, (1L << 6), mouse_move_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	write(1, "3\n", 2);
	mlx_loop(e->ptr);
	return (0);
}
