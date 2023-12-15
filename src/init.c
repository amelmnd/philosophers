/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:58:02 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 18:18:44 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char *argv[])
{
	int	i;

	i = 0;
	data->nb_philo = philo_atoi(argv[1]);
	data->time_to_die = philo_atoi(argv[2]);
	data->time_to_eat = philo_atoi(argv[3]);
	data->time_to_sleep = philo_atoi(argv[4]);
	data->nb_meals = 0;
	if (argv[5] != NULL)
		data->nb_meals = philo_atoi(argv[5]);
	data->nb_philo_ready = 0;
	pthread_mutex_init(&data->mutex_philo_ready, NULL);
	data->nb_philo_finished = 0;
	pthread_mutex_init(&data->mutex_philo_finished, NULL);
	pthread_mutex_init(&data->mutex_message, NULL);
	pthread_mutex_init(&data->mutex_is_dead, NULL);
	data->mutex_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->mutex_forks[i], NULL);
		i++;
	}
	data->philo = (t_philo **)malloc(sizeof(t_philo *) * data->nb_philo);
	return (0);
}

void	manage_philo_fork(t_data *data, int i)
{
	printf("(i + 1)  data->nb_philo = %d\n ", (i + 1) % data->nb_philo);
	if (i % 2 == 0)
	{
		data->philo[i]->mutex_l_fork = &data->mutex_forks[i];
		data->philo[i]->mutex_r_fork = &data->mutex_forks[(i + 1)
			% data->nb_philo];
	}
	else if (i % 2)
	{
		data->philo[i]->mutex_l_fork = &data->mutex_forks[(i + 1)
			% data->nb_philo];
		data->philo[i]->mutex_r_fork = &data->mutex_forks[i];
	}
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		data->philo[i]->data = data;
		data->philo[i]->nb_philo = data->nb_philo;
		data->philo[i]->time_to_die = data->time_to_die;
		data->philo[i]->time_to_eat = data->time_to_eat;
		data->philo[i]->time_to_sleep = data->time_to_sleep;
		data->philo[i]->nb_meals = data->nb_meals;
		data->philo[i]->id_philo = i + 1;
		data->philo[i]->last_meal = 0;
		data->philo[i]->nb_eats = 0;
		data->philo[i]->philo_status = EATING;
		// if (data->philo[i]->id_philo % 2)
		// 	data->philo[i]->philo_status = THINKING;
		manage_philo_fork(data, i);
		// ne sert a rien
		// pthread_mutex_init(data->philo[i]->mutex_l_fork, NULL);
		// pthread_mutex_init(data->philo[i]->mutex_r_fork, NULL);
		data->philo[i]->lock_l_fork = FALSE;
		data->philo[i]->lock_r_fork = FALSE;
		i++;
	}
}

int	initialize(char *argv[], t_data *data)
{
	init_data(data, argv);
	init_philo(data);
	return (0);
}