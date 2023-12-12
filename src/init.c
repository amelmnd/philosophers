/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:48:04 by amennad           #+#    #+#             */
/*   Updated: 2023/12/12 09:51:00 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo, int i)
{
	philo->data = data;
	philo->eating = FALSE;
	philo->start_time = 0;
	philo->last_meal = 0;
	philo->id_philo = i;
	philo->id_fork = i;
	philo->start_eat = 0;
	philo->nb_eats = 0;
	philo->philo_status = EATING;
	pthread_mutex_init(&data->forks[i], NULL);
	philo->l_fork = &data->forks[i];
	philo->r_fork = &data->forks[(i + 1) % data->nb_philo];
	philo->nb_forks = 0;
}

void	initialize(t_data *data, t_philo *philos)
{
	int i;

	i = 0;
	data->dead = FALSE;
	data->start_meat = ft_time();
	// for stand init all philos
	data->philos_thread = (pthread_t *)malloc(data->nb_philo
			* sizeof(pthread_t));
	data->forks = (pthread_mutex_t *)malloc(data->nb_philo
			* sizeof(pthread_mutex_t));

	while (i < (int)data->nb_philo)
	{
		init_philo(data, &philos[i], i);

		pthread_create(&data->philos_thread[i], NULL, routine, &philos[i]);
		if (data->dead)
			break ;
	}
}