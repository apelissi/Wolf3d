/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:55 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/12 13:19:25 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef WOLF_H
#		define WOLF_H

#include "color.h"
#include "math.h"
#include "keyboard.h"
#include "../Libft/libft.h"
#include "../miniLibX/mlx.h"

#define VD 5
#define VR 4
#define	TS 200
#define PI 3.14159265359

typedef	struct		s_map
{
	char	**grid;
	int		*data_map;
	void	*img_map;
	int		t_x;
	int		t_y;
	int		img_x;
	int		img_y;
}					t_map;

typedef	struct		s_perso
{
	int		x_map;
	int		y_map;
	int		pos_x;
	int		pos_y;
	int		pos_z;
	int		mv_x;
	int		mv_y;
	int		mv_r;
	int		angle;
}					t_perso;

typedef struct		s_env
{
	int		f;
	t_perso	*pe;
	t_map	*map;
	void	*ptr;
	void	*win;
	int		*data;
	int		win_x;
	int		win_y;
	void	*img;
}					t_env;

int		ft_mlx(t_env *e);
int		deal_key(int key, t_env *te);
int		get_map(t_map *map, int fd);
void	print_map(char **grid);
void	get_grid(t_env *e);
void	get_perso(t_env *e, t_perso *p);
int		key_press(int k, t_env *e);
int		key_release(int k, t_env *e);
int		expose_hook(t_env *e);
void	erase_player(t_env *e, int y_map, int x_map);
void	get_view(t_env *e);

#		endif
