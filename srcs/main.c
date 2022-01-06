/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:58:08 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/05 10:58:10 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_gen	gen;

	if (ac == 5 || ac == 6)
	{
		if (ft_pars_arg(av) == -1)
		{
			ft_putstr("Error: Invalid Argument\n");
			return (1);
		}
		return (0);
	}
	return (ft_error());
}
