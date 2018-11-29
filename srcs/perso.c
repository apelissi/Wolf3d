/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:07:31 by apelissi          #+#    #+#             */
/*   Updated: 2018/11/29 18:12:22 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	init_map(char **map)
{
	int	i;

	i = 6;
	map = (char **)malloc(6 * sizeof(char *));
	while (i)
	{
		map[i] = (char *)malloc(6 * sizeof(char));
		i--;
	}
	map[0] = "11111";
	map[1] = "10001";
	map[2] = "10001";
	map[3] = "10001";
	map[4] = "11111";
}

t_env	*init_env(void)
{
	t_env	*te;

	te = (t_env *)malloc(sizeof(t_env));
	te->pe = (t_perso *)malloc(sizeof(t_perso));
	te->pe->pos_x = 0;
	te->pe->pos_y = 0;
	te->pe->angle = 0;
	init_map(te->map);
	return (te);
}

int 	main(void)
{
	t_env		*te;

	te = init_env();
	ft_putnbr(te->pe->pos_x);
	ft_mlx(te);
	return (0);
}
