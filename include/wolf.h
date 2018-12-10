/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:55 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/10 16:43:02 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef WOLF_H
#		define WOLF_H

#include "color.h"
#include "math.h"
#include "keyboard.h"
#include "../Libft/libft.h"
#include "../miniLibX/mlx.h"

#define VD 10
#define VR 5
#define	TS 200
#define PI 3.14159265358

typedef	struct		s_map
{
	char	**grid;
	int		t_x;
	int		t_y;
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
	int		*data_map;
	int		win_x;
	int		win_y;
	void	*img;
	void	*img_map;
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

#		endif
