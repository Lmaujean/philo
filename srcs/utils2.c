/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:19:40 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/17 11:19:41 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	unsigned long int	atoi;
	int					i;
	int					symbole;

	i = 0;
	symbole = 1;
	atoi = 0;
	while (ft_isdigit(str[i]))
	{
		atoi = (atoi * 10) + (str[i] - 48);
		i++;
	}
	return ((int)(atoi * symbole));
}

long int	ft_atoi_long(const char *str)
{
	unsigned long int	atoi;
	int					i;
	int					symbole;

	i = 0;
	symbole = 1;
	atoi = 0;
	while (ft_isdigit(str[i]))
	{
		atoi = (atoi * 10) + (str[i] - 48);
		i++;
	}
	return ((atoi * symbole));
}

long int	ft_get_time(void)
{
	struct timeval	act;

	gettimeofday(&act, NULL);
	return ((act.tv_sec * 1000) + (act.tv_usec / 1000));
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->gen->print);
	if (philo->gen->alive == 1)
	{
		printf("%ld ms %d %s\n", ft_get_time() - philo->gen->start_meal, \
		philo->id, str);
	}
	pthread_mutex_unlock(&philo->gen->print);
}

void	ft_usleep(long int time)
{
	long int	tmp;

	tmp = ft_get_time();
	while ((ft_get_time() - tmp) < time)
		usleep(time);
}