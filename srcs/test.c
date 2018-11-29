/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:24:39 by apelissi          #+#    #+#             */
/*   Updated: 2018/11/29 13:45:20 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int main(void)
{
	void	*ptr;
	void	*win;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 1000, 300, "odfhibfhiufdhuibf");
	mlx_loop(ptr);
	return (0);
}
