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
	gen->philos = malloc(sizeof(t_philo) * gen->nbr_philo);
	if (!gen->philos)
		return (1);
	while (i < gen->nbr_philo)
	{
		gen->philos[i].id = i + 1;
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

void	*start_philo(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->gen->nbr_philo == 1)
		ft_print(philo, "has taken a fork");
	if (philos->id % 2 == 0)
		ft_usleep(philos->gen->time_to_sleep, philo);
	while (philos->gen->alive == 1 && \
	philos->ate != philos->gen->nbr_meal)
	{
		ft_philo_eat(philos);
		ft_philo_sleep(philos);
	}
	pthread_mutex_lock(&philos->gen->eat);
	philos->gen->all_ate++;
	pthread_mutex_unlock(&philos->gen->eat);
	return (NULL);
}

int	init_dinner(t_gen *gen)
{
	int	i;

	i = 0;
	gen->alive = 1;
	gen->start_meal = ft_get_time();
	if (!init_philo(gen))
	{
		while (i < gen->nbr_philo && gen->alive == 1)
		{
			if (ft_get_time() - gen->start_meal > gen->time_to_die)
			{
				gen->alive = 0;
				usleep(1000);
				printf("%ld %d", ft_get_time() - gen->start_meal, i + 1);
				gen->nbr_philo = i + 1;
				return (1);
			}
			gen->philos[i].last_meal = gen->start_meal;
			if (pthread_create(&gen->philos[i].philo, NULL, start_philo, \
			&gen->philos[i]))
				return (ft_error(3));
			i++;
		}
		return (0);
	}
	return (1);
}
