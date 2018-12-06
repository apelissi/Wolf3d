/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:06:02 by apelissi          #+#    #+#             */
/*   Updated: 2018/12/06 12:27:56 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_env	*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(e->pe = (t_perso *)malloc(sizeof(t_perso))))
		return (NULL);
	return (e);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	*e;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !(e = init_env()))
		return (0);
	if (!(get_map(e->map, fd)))
		return (0);
	print_map(e->map->grid);
	ft_mlx(e);
	return (0);
}
