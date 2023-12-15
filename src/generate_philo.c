/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:22:38 by amennad           #+#    #+#             */
/*   Updated: 2023/12/14 17:39:18 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_alone(t_data *data)
{
	data->start_meal = ft_get_time();
	print_status(data, 0, "has taken a fork", C_EAT);
	data->philo_dead = TRUE;
	print_status(data, 0, "died", C_DEAD);
	data->philo->philo_status = DEAD;
	return (0);
}

int	init_threads(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo_dead = FALSE;
	data->start_meal = ft_get_time();
	while (i < data->nb_philo)
	{
		try_lock(&data->mutex_n_thread);
		data->n_thread = i;
		try_unlock(&data->mutex_n_thread);
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				(void *)data) != 0)
			return (1);
		usleep(1000);
		i++;
	}
	if (pthread_create(&data->check_is_dead, NULL, &is_dead, (void *)data) != 0)
		return (1);
	usleep(1000);
	return (0);
}

int	join_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(data->check_is_dead, NULL) != 0)
		return (1);
	return (0);
}

int	the_meal(t_data *data)
{
	if (init_threads(data) == 1)
		return (1);
	if (join_threads(data) == 1)
		return (1);
	return (0);
}
