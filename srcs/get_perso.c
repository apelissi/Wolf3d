/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:46:04 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/10 17:19:13 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	make_player(t_env *e, int y_map, int x_map, int i)
{
	int	a;
	int b;

	a = (y_map > i) ? y_map - i : 0;
	while (a <= e->win_y && a <= y_map + i)
	{
		b = (x_map > i) ? x_map - i : 0;
		while (b <= e->win_x && b <= x_map + i)
		{
			e->data_map[a * e->win_x + b] = (i == 3) ? BLUE : RED;
			b++;
		}
		a++;
	}

}

void	get_perso(t_env *e, t_perso *p)
{	
	p->angle += p->mv_r * VR;
	p->angle = (p->angle >= 360) ? p->angle % 360 : p->angle;
	p->angle = (p->angle < 0) ? 360 + p->angle : p->angle;
	p->pos_x += sin((float)p->angle / 180 * PI) * (float)VD * (float)p->mv_y;
	p->pos_y += cos((float)p->angle / 180 * PI) * (float)VD * (float)p->mv_y;
//	p->pos_x += cos((float)p->angle / 180 * PI) * (float)VD * (float)p->mv_x;
//	p->pos_y += sin((float)p->angle / 180 * PI) * (float)VD * (float)p->mv_x;
	if (p->pos_x >= 0 && p->pos_x < TS * e->map->t_x)
		p->x_map = p->pos_x * (float)e->win_x / (TS * e->map->t_x);
	if (p->pos_y >= 0 && e->pe->pos_y < TS * e->map->t_y)
		p->y_map = p->pos_y * (float)e->win_y / (TS * e->map->t_y);
	make_player(e, p->y_map, p->x_map, 3);


	p->pos_x += 8 * sin((float)p->angle * PI / 180) * VD;
	p->pos_y += 8 * cos((float)p->angle * PI / 180) * VD;
	if (p->pos_x >= 0 && p->pos_x < TS * e->map->t_x)
		p->x_map = p->pos_x * e->win_x / (TS * e->map->t_x);
	if (p->pos_y >= 0 && e->pe->pos_y < TS * e->map->t_y)
		p->y_map = p->pos_y * e->win_y / (TS * e->map->t_y);
	make_player(e, p->y_map, p->x_map, 1);
	p->pos_x -= 8 * sin((float)p->angle * PI / 180) * VD;
	p->pos_y -= 8 * cos((float)p->angle * PI / 180) * VD;

}
