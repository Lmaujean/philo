/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:49:39 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/06 12:49:43 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

int	ft_error(void)
{
	ft_putstr("Error argument\n");
	return (0);
}

const int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

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
