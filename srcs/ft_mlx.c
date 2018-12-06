/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:25:58 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/06 16:01:06 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	init(t_env *e)
{
	e->win_x = 500;
	e->win_y = 500;
	e->f = 0;
}

int		expose_hook(t_env *e)
{
	int	i;

	i = 0;
	write(1, "a\n", 2);
	if (e->f == 0)
	{
		e->img_map = mlx_new_image(e->ptr, e->win_x, e->win_y);
		e->data_map = (int *)mlx_get_data_addr(e->img_map, &i, &i, &i);
		fill_img(e);
		e->f = e->f + 1;
	}
	write(1, "b\n", 2);
	mlx_put_image_to_window(e->ptr, e->win, e->img_map, 0, 0);
	write(1, "c\n", 2);
//	mlx_destroy_image(e->ptr, e->img_map);
	return (i);
}

int		ft_mlx(t_env *e)
{
	init(e);
	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, e->win_x, e->win_y, "TEST");
	//	mlx_key_hook(e->win, deal_key, e);
	//	mlx_mouse_hook(e->win, deal_mouse, e);
	//	mlx_hook(e->win, 6, (1L << 6), mouse_move_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->ptr);
	return (0);
}
