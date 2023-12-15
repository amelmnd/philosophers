/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:56:17 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 16:28:50 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_free(t_data *data, int ret)
{
	if (data->philo != NULL)
		free(data->philo);
	if (data->mutex_forks != NULL)
		free(data->mutex_forks);
	free(data);
	return (ret);
}

int	free_destroy(t_data *data, t_bool error)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(data->philo[i]->mutex_l_fork);
		pthread_mutex_destroy(data->philo[i]->mutex_r_fork);
		pthread_mutex_destroy(&data->mutex_forks[i]);
		pthread_detach(data->philo[i]->thread_philo);
		free(data->philo[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_philo_ready);
	pthread_mutex_destroy(&data->mutex_philo_finished);
	pthread_mutex_destroy(&data->mutex_message);
	pthread_mutex_destroy(&data->mutex_is_dead);
	free(data->mutex_forks);
	free(data->philo);
	free(data);
	return (error);
}
