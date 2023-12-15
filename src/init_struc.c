/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:22:24 by amennad           #+#    #+#             */
/*   Updated: 2023/12/13 18:48:57 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_data *data)
{
	size_t	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo + 1);
	if (data->forks == NULL)
		return (1);
	i = 0;
	if (pthread_mutex_init(&data->str_message, NULL) != 0)
		return (1);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		printf("i: %zu\n", i);
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	size_t	i;
	size_t	j;

	// t_philo	**philos;
	i = 0;
	j = 1;
	data->philo = malloc(sizeof(t_philo) * (data->nb_philo + 1));
	if (data->philo == NULL)
		return (1);
	while (j <= data->nb_philo)
	{
		if (j == data->nb_philo)
			j = 0;
		data->philo[i].id_philo = i + 1;
		data->philo[i].l_fork = &data->forks[i];
		data->philo[i].r_fork = &data->forks[(i + 1) % data->nb_philo];
		data->philo[i].nb_eats = 0;
		data->philo[i].eating = FALSE;
		data->philo[i].start_time = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].id_fork = i;
		data->philo[i].start_eat = 0;
		data->philo[i].philo_status = EATING;
		data->philo[i].nb_forks = 0;
		if (i % 2)
		{
			data->philo[i].l_fork = &data->forks[(i + 1) % data->nb_philo];
			data->philo[i].r_fork = &data->forks[i];
		}
		i++;
		if (j == 0)
			break ;
		j++;
	}
	return (0);
}

int	initialize(t_data *data)
{
	// t_philo	*philos;
	if (ft_init_mutex(data) == 1)
	{
		free(data->philo);
		free(data->forks);
		printf("Error initialization of mutex\n");
		return (1);
	}
	if (init_philo(data) == 1)
	{
		free(data->philo);
		free(data->forks);
		printf("Error initialization of philo\n");
		return (1);
	}
	return (0);
}
