/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_meal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:34:08 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 17:09:23 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->philo_dead = FALSE;
	data->start_meal = ft_get_time();
	while (i < data->nb_philo)
	{
		data->philo[i]->last_meal = ft_get_time();
		ft_try_lock(&data->mutex_n_philo);
		data->n_philo = i;
		ft_try_unlock(&data->mutex_n_philo);
		if (pthread_create(&data->philo[i]->thread_philo, NULL, &philo_routine,
				(void *)data) != 0)
			return (1);
		ft_try_lock(&data->mutex_philo_ready);
		data->nb_philo_ready++;
		ft_try_unlock(&data->mutex_philo_ready);
		usleep(1000);
		i++;
	}
	return (0);
}
int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i]->thread_philo, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(data->thread_monitoring, NULL) != 0)
		return (1);
	return (0);
}
int	philo_alone(t_data *data)
{
	data->start_meal = ft_get_time();
	print_status(data, 0, "has taken a fork", C_EAT);
	ft_try_lock(&data->mutex_is_dead);
	data->philo_dead = TRUE;
	ft_try_unlock(&data->mutex_is_dead);
	print_status(data, 0, "died", C_DEAD);
	return (free_destroy(data, FALSE));
}

int	the_meal(t_data *data)
{
	(void)data;
	if (data->nb_philo == 1)
		return (philo_alone(data));
	if (init_threads(data) == 1)
		return (1);
	if (join_threads(data) == 1)
		return (1);
	return (0);
}