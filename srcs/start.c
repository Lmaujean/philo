#include "../includes/philo.h"

int	init_philo(t_gen *gen)
{
	int i;

	i = 0;
    gen->philos = malloc(sizeof(t_philo) * gen->nbr_philo);
	if (!gen->philos)
		return (1);
	while (i < gen->nbr_philo)
	{
		if (pthread_mutex_init(&gen->philos[i].fork, NULL))
		{
			free(gen->philos);
			return (1);
		}
		if (i == gen->nbr_philo - 1)
			gen->philos[i].next_fork = &gen->philos[0].fork;
		else
			gen->philos[i].next_fork = &gen->philos[i + 1].fork;
		gen->philos[i].gen = gen;
		i++;
	}
	if (pthread_mutex_init(&gen->print, NULL))
		return (1);
	return (0);
}

void	*start_philo(void *philo) // cette fonction gère la vie des philo. Faire des sous fonctions.
{
	t_philo *philos;

	philos = (t_philo *)philo;
	pthread_mutex_lock(&philos->gen->print);
	printf("hello alive value == %d\n", philos->gen->alive);
	philos->gen->alive++;
	pthread_mutex_unlock(&philos->gen->print);
	return (NULL);
}

int	init_dinner(t_gen *gen)
{
	int i;

	i = 0;
	gen->alive = 0;
	while (i < gen->nbr_philo)
	{
		pthread_create(&gen->philos[i].philo, NULL, start_philo, &gen->philos[i]);
		i++;
	}
	i = 0;
	while (i < gen->nbr_philo)
	{
		pthread_join(gen->philos[i].philo, NULL);
		i++;
	}
	return (0);
}