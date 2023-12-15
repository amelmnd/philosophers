/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:56:17 by amennad           #+#    #+#             */
/*   Updated: 2023/12/13 14:28:59 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	try_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
	{
		printf("thread unlock error\n");
		exit(EXIT_FAILURE);
	}
}

int	philo_free(t_data *data, int ret)
{
	if (data->philo != NULL)
		free(data->philo);
	if (data->forks != NULL)
		free(data->forks);
	free(data);
	return (ret);
}

int	destroy_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		free(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->str_message);
	return (0);
}
