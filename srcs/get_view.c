/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:10:07 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/13 18:19:44 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	point(int x, int y, t_map *m)
{
	int	x_m;
	int	y_m;

	x_m = x * m->img_x / (TS * m->t_x);
	y_m = y * m->img_y / (TS * m->t_y);
	m->data_map[x_m + y_m * m->img_x] = RED;
}

void	make_co(int h, int i, t_env *e)
{
	int a;

	a = 0;
	i =  e->win_x - i;
	while (a < e->win_y) 
	{			
		e->data[i + e->win_x * a] = (a > (e->win_y - h) / 2 && a < (e->win_y + h) / 2) ? 
									G3 : G1;
		a++;
	}
}


float		raycast(float d, t_perso *p, t_map *m)
{
	float	x_t;
	float	y_t;
	int		h;

	x_t = p->pos_x;
	y_t = p->pos_y;
	while (x_t > 0 && x_t < m->t_x * TS && y_t > 0 && y_t < m->t_y * TS
			&& (m->grid[(int)(x_t / TS)][(int)(y_t / TS)] != '1'))
	{
		point((int)x_t, (int)y_t, m);
		x_t = x_t + sin(d / 180 * PI);
		y_t = y_t + cos(d / 180 * PI);
	}
	h = 0;
	return (hypotf((float)(p->pos_x) - x_t, (float)(p->pos_y) - y_t));
}

void	get_view(t_env *e)
{
	int	i;
	float	d_mur;
	float	d_ecr;
	float	h;
	float	d;

	i = 0;
	d_ecr = (float)e->win_x / (2 * tan(30 * PI / 180));
	while (i <= e->win_x)
	{
		d = (float)e->pe->angle - 30 + (float)i * 60 / (float)e->win_x;
		d = (d < 0) ? 360 - d : d;
		d = (d >= 360) ? d - 360 : d;
		d_mur = raycast(d, e->pe, e->map);
		d = (d > (float)e->pe->angle) ? d - (float)e->pe->angle : (float)e->pe->angle - d;
		d_mur = d_mur * cosf(d / 180 * PI);
		h = (d_ecr * TS) / d_mur;
		make_co((int)h, i, e);
		i++;
	}

}
