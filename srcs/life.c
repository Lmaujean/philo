/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:25:25 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/17 11:25:42 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_eat(t_philo *philo)
{
	if (philo->gen->alive == 1)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(philo->next_fork);
		ft_print(philo, "has taken a fork");
		philo->last_meal = ft_get_time();
		ft_print(philo, "is eating");
		philo->ate++;
		ft_usleep(philo->gen->time_to_eat, philo);
	}
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
	if (philo->gen->alive == 1)
	{
		ft_usleep(philo->gen->time_to_sleep, philo);
		ft_print(philo, "is thinking");
	}
}

void	ft_check_death(t_gen *gen)
{
	int	i;

	i = 0;
	while (i < gen->nbr_philo && gen->all_ate != gen->nbr_meal && \
	gen->alive == 1)
	{
		if (ft_get_time() - gen->philos[i].last_meal > gen->time_to_die)
		{
			gen->alive = 0;
			printf("%ld %d Died !\n", ft_get_time() - gen->start_meal, \
			gen->philos[i].id);
			return ;
		}
		i++;
	}
}

void	ft_clean_meal(t_gen *gen)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&gen->print);
	pthread_mutex_destroy(&gen->print);
	while (i < gen->nbr_philo)
	{
		pthread_mutex_unlock(&gen->philos[i].fork);
		pthread_mutex_destroy(&gen->philos[i].fork);
		pthread_mutex_unlock(gen->philos[i].next_fork);
		pthread_mutex_destroy(gen->philos[i].next_fork);
		pthread_join(gen->philos[i].philo, NULL);
		i++;
	}
}
