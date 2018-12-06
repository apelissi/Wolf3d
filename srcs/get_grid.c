/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:58:12 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/06 15:57:41 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		get_color(char c)
{
	if (c == '0')
		return (G4);
	if (c == '1')
		return (G1);
	else
		return (BLACK);
}

void	make_line(t_env *e)
{
	int	a;
	int	b;
	int	color;
	int	width;
	int height;

	color = get_color('B');
	height = e->win_y / e->map->t_y;
	a = 0;
	while (a <= e->win_y)
	{
		b = 0;
		while (b <= e->win_x)
		{
			e->data_map[a * e->win_x + b] = color;
			b++;
		}
		a = a + height;
	}
}

void	make_column(t_env *e)
{
	int	a;
	int	b;
	int	color;
	int	width;
	int height;

	color = get_color('B');
	width = e->win_x / e->map->t_x;
	b = 0;
	while (b <= e->win_x)
	{
		a = 0;
		while (a <= e->win_y)
		{
			e->data_map[a * e->win_x + b] = color;
			a++;
		}
		b = b + width;
	}
}

void	make_rectangle(int i, int j, t_env *e)
{
	int	a;
	int	b;
	int	width;
	int height;
	int	color;

	color = get_color(e->map->grid[i][j]);
	height = e->win_y / e->map->t_y;
	width = e->win_x / e->map->t_x;
	a = i * height;
	while (a < (i + 1) * height)
	{
		b = j * width;
		while (b < (j + 1) * width)
		{
			e->data_map[a * e->win_x + b] = color;
			b++;
		}
		a++;
	}
}

void	get_grid(t_env *e)
{
	int i;
	int	j;

	i = 0;
	while (i < e->map->t_y)
	{
		j = 0;
		while (j < e->map->t_x)
		{
			make_rectangle(i, j, e);
			j++;
		}
		i++;
	}
	make_line(e);
	make_column(e);
}
