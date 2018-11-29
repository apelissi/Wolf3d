/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:55 by apelissi          #+#    #+#             */
/*   Updated: 2018/11/29 17:53:23 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef WOLF_H
#		define WOLF_H

#include "math.h"
#include "keyboard.h"
#include "../Libft/libft.h"
#include "../miniLibX/mlx.h"

typedef	struct		s_perso
{
	int		pos_x;
	int		pos_y;
	int		pos_z;
	float	angle;

}					t_perso;

typedef struct		s_env
{
	t_perso	*pe;
	char	**map;
	void	*ptr;
	void	*win;
	void	*img;
}					t_env;

int		ft_mlx(t_env *te);
int		deal_key(int key, t_env *te);

#		endif
