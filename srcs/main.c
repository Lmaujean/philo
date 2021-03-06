/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:58:08 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/18 17:47:55 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_gen	gen;

	if (ac == 5 || ac == 6)
	{
		if (stock_arg(&gen, av))
			return (ft_error(1));
		if (init_dinner(&gen))
			return (ft_error(3));
		while (gen.alive == 1 && gen.all_ate != gen.nbr_philo)
			ft_check_death(&gen);
		ft_clean_meal(&gen);
		free(gen.philos);
		gen.philos = NULL;
		return (0);
	}
	return (ft_error(1));
}
