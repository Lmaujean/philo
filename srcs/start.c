/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:41:02 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/17 11:41:04 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_gen *gen)
{
	int	i;

	i = 0;
	while (i < gen->nbr_philo)
	{
		if (pthread_mutex_init(&gen->philos[i].fork, NULL))
		{
			free(gen->philos);
			return (2);
		}
		if (i == gen->nbr_philo - 1)
			gen->philos[i].next_fork = &gen->philos[0].fork;
		else
			gen->philos[i].next_fork = &gen->philos[i + 1].fork;
		gen->philos[i].gen = gen;
		i++;
	}
	if (pthread_mutex_init(&gen->print, NULL))
		return (3);
	return (0);
}

void	*start_phi(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->gen->nbr_philo == 1)
		ft_print(philo, "has taken a fork");
	while (philos->gen->alive == 1 && \
	philos->ate != philos->gen->nbr_meal)
	{
		ft_philo_eat(philos);
		ft_philo_sleep(philos);
	}
	return (NULL);
}

int	init_dinner(t_gen *gen)
{
	int	i;

	i = 0;
	gen->philos = malloc(sizeof(t_philo) * gen->nbr_philo);
	if (!gen->philos)
		return (1);
	gen->alive = 1;
	gen->start_meal = ft_get_time();
	if (!init_philo(gen))
	{
		gen->philos->id = i;
		while (i < gen->nbr_philo)
		{
			pthread_create(&gen->philos[i].philo, NULL, start_phi, \
			&gen->philos[i]);
			i++;
		}
		i = 0;
		while (i < gen->nbr_philo)
		{
			pthread_join(gen->philos[i].philo, NULL);
			i++;
		}
		return (1);
	}
	return (0);
}
