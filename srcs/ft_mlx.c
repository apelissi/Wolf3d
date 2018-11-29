/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:29:12 by apelissi          #+#    #+#             */
/*   Updated: 2018/11/29 18:16:39 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_mlx(t_env *te)
{

	te->ptr = mlx_init();
	te->win = mlx_new_window(te->ptr, 500, 500, "BIBI");
	mlx_key_hook(te->win, deal_key, te);
//	mlx_mouse_hook(te->win, deal_mouse, te);
//	mlx_hook(te->win, 6, (1L << 6), mouse_move_hook, te);
//	mlx_expose_hook(te->win, expose_hook, te);
	mlx_loop(te->ptr);
	return (0);
}
