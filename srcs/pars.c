/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:39:27 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/06 11:39:29 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_int(char *av)
{
	unsigned long	res;
	int				i;

	res = 0;
	i = 0;
	while (av[i] >= '0' && av[i] <= '9')
	{
			res = (res * 10) + (av[i++] -48);
		if (res > 2147483647)
			return (1);
	}
	return (0);
}

int	check_long(char *av)
{
	unsigned long long	res;
	int					i;

	res = 0;
	i = 0;
	while (av[i] >= '0' && av[i] <= '9')
	{
			res = (res * 10) + (av[i++] -48);
		if (res > 9223372036854775807)
			return (1);
	}
	return (0);
}

int	ft_pars_arg(char *av, int index)
{
	if (!ft_strisdigit(av))
		return (1);
	if (index == 1 || index == 5)
	{
		if (check_int(av))
			return (1);
	}
	else
	{
		if (check_long(av))
			return (1);
	}
	return (0);
}

int	stock_arg(t_gen *gen, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_pars_arg(av[i], i))
			return (1);
		else if (i == 1)
			gen->nbr_philo = ft_atoi(av[i]);
		else if (i == 2)
			gen->time_to_die = ft_atoi_long(av[i]);
		else if (i == 3)
			gen->time_to_eat = ft_atoi_long(av[i]);
		else if (i == 4)
			gen->time_to_sleep = ft_atoi_long(av[i]);
		else if (i == 5)
			gen->nbr_meal = ft_atoi(av[i]);
		i++;
	}
	if (i == 5)
		gen->nbr_meal = -1;
	if (gen->nbr_philo < 1 || gen->nbr_meal == 0)
		return (1);
	return (0);
}
