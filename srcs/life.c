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
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->next_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->gen->eat);
	philo->last_meal = ft_get_time();
	ft_print(philo, "is eating");
	philo->ate++;
	pthread_mutex_unlock(&philo->gen->eat);
	ft_usleep(philo->gen->time_to_eat);
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
	ft_usleep(philo->gen->time_to_sleep);
	ft_print(philo, "is thinking");
}

void	ft_check_death(t_gen *gen)
{
	int	i;

	i = 0;
	
}