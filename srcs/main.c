/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:58:08 by lmaujean          #+#    #+#             */
/*   Updated: 2022/01/05 10:58:10 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *test_tread(void)
{
    printf("le thread marche pas trop mal\n");
    sleep(3);
    printf("le thread se termine\n");
}

void    *test_tread2(void)
{
    printf("le thread 2 marche pas trop mal\n");
    sleep(3);
    printf("le thread 2 se termine\n");
}

int    main(void)
{
    pthread_t    t1;
    pthread_t    t2;

    pthread_create(&t1, NULL, &test_tread, NULL);
    pthread_create(&t2, NULL, &test_tread2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}
