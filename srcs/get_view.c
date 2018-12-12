/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:10:07 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/12 17:27:17 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	make_co(int h, int i, t_env *e)
{
	int a;

	ft_putnbr(h);
	write(1, "\n", 1);
	if (h > 200)
		h = 200;
	h = 20;
	a = 100 - h / 2;
	while (a < 100 + h / 2)
	{
		e->data[i + a * e->win_x] = RED;
		a++;
	}
}

int	raycast(int i, t_perso *p, t_map *m, t_env *e)
{
	float   d;
	int     dir_y;
	int     dir_x;
	int     x_t;
	int     y_t;
	float   dif_x;
	float   dif_y;
	float   d1;
	float   d2;
	float   dist;
	int		h;

	write(1, "0\n", 2);
	d = (float)p->angle - 30 + (float)i * 60 / (float)e->win_x;
	d = (d < 0) ? 360 - d : d;
	dir_y = (d > 90 && d < 270) ? -1 : 1;
	x_t = p->pos_x;
	y_t = p->pos_y;
	while (x_t % 200 != 0 && sin((float)p->angle / 180 * PI))
	{
		ft_putnbr(x_t);
		write(1, "\n", 1);
		x_t = x_t + sin((float)p->angle / 180 * PI);
		y_t = y_t + cos((float)p->angle / 180 * PI);
	}
	if (x_t % 200 == 0)
	{
		dif_x = 200 / tan(d * 180 / PI);
		write(1, "1\n", 2);
		while (x_t <= m->t_x * TS && x_t > 0 && y_t <= m->t_y * TS && y_t > 0
				&& m->grid[(int)x_t / TS][y_t / TS] != '1')
		{
			x_t += dif_x;
			y_t += dir_y * 200;
		}
		write(1, "2\n", 2);
		d1 = hypotf((float)(x_t - p->pos_x), (float)(y_t - p->pos_y));
	}
	else
		d1 = -1;

	dir_x = (d > 180) ? -1 : 1;
	x_t = p->pos_x;
	y_t = p->pos_y;
	while (y_t % 200 != 0 && cos((float)p->angle / 180 * PI))
	{
		x_t = x_t + sin((float)p->angle / 180 * PI);
		y_t = y_t + cos((float)p->angle / 180 * PI);
	}
	if (y_t % 200 != 0)
	{
		write(1, "3\n", 2);
		dif_y = 200 / tan(d * 180 / PI);
		while (x_t <= m->t_x * TS && x_t > 0 && y_t <= m->t_y * TS && y_t > 0
				&& m->grid[x_t / TS][(int)(y_t + dif_y / 2) / TS])
		{
			x_t += dir_x * 200;;
			y_t += dif_y;
		}
		write(1, "4\n", 2);
		d2 = hypotf((float)(x_t - p->pos_x), (float)(y_t - p->pos_y));
	}
	else
		d2 = -1;
	if (d1 < 0)
		dist = d2;
	else if (d2 < 0)
		dist  = d1;
	else
		dist = (d1 > d2) ? d1 : d2;

	h = (277 * 200) / dist;
	return (h);
}

void	get_view(t_env *e)
{
	int	i;
	int h;

	i = 0;
	while (i <= e->win_x)
	{
		write(1, "A\n", 2);
		h = raycast(i, e->pe, e->map, e);
		write(1, "B\n", 2);
		make_co(h, i , e);
		write(1, "C\n", 2);
		i++;
	}

}
