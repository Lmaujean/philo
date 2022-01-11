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
# include <stdlib.h>

/******* STRUC PHILO *******/

typedef struct s_gen t_gen;

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	long int		last_meal;
	t_gen			*gen;
}				t_philo;

typedef struct s_gen
{
	int				alive;
	int				nbr_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				nbr_meal;
	t_philo			*philos;
	pthread_mutex_t	print;
}				t_gen;

/******* FONCTION PHILO *******/

int			ft_pars_arg(char *av, int index);
int			stock_arg(t_gen *gen, char **av);
int  		init_philo(t_gen *gen);
int			init_dinner(t_gen *gen);

/******* FONCTION UTILS *******/

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_error(char *str);
int			ft_atoi(const char *str);
int			ft_strisdigit(char *str);
long int	ft_atoi_long(const char *str);

#endif
