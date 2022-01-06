/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:58:24 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/05 10:58:25 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

/******* STRUC PHILO *******/

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
}				t_philo;

typedef struct s_gen
{
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_meal;
	t_philo		*philos;
}				t_gen;

/******* FONCTION PHILO *******/

int		ft_pars_arg(char **av);
int		ft_get_arg(char **av, t_gen *gen);

/******* FONCTION UTILS *******/

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_error(void);
int		ft_atoi(const char *str);
int		ft_strisdigit(char *str);

#endif
