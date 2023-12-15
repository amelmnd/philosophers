/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:06:12 by amennad           #+#    #+#             */
/*   Updated: 2023/12/13 18:51:45 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_data *data, int i)
{
	try_lock(data->philo->l_fork);
	// if (pthread_mutex_lock(data->philo->l_fork) != 0)
	// return (1);
	if (print_status(data, data->philo[i].id_philo, "has taken a fork",
			C_FORK) == 1)
		return (1);
	// if (pthread_mutex_lock(data->philo->r_fork) != 0)
	// return (1);
	try_lock(data->philo->r_fork);
	if (print_status(data, data->philo[i].id_philo, "has taken a fork",
			C_FORK) == 1)
		return (1);
	return (0);
}

int	drop_fork(t_data *data, int i)
{
	(void)i;
	if (pthread_mutex_unlock(data->philo->l_fork) != 0)
		return (1);
	if (pthread_mutex_unlock(data->philo->r_fork) != 0)
		return (1);
	return (0);
}

int	philo_life(t_data *data, size_t i)
{
	if (data->philo->philo_status == DEAD)
		return (1);
	if (data->philo->philo_status == EATING)
	{
		if (take_fork(data, i) == 1)
			return (1);
		if (print_status(data, data->philo[i].id_philo, "is eating",
				C_EAT) == 1)
			return (1);
		data->philo[i].last_meal = ft_get_time();
		usleep(data->time_to_eat * 1000);
		if (drop_fork(data, i) == 1)
			return (1);
		data->philo[i].nb_eats++;
		data->philo[i].philo_status = SLEEPING;
	}
	if (data->philo[i].philo_status == SLEEPING)
	{
		if (print_status(data, data->philo[i].id_philo, "is sleeping",
				C_SLEEP) == 1)
			return (1);
		usleep(data->time_to_sleep * 1000);
		data->philo[i].philo_status = THINKING;
	}
	if (data->philo[i].philo_status == THINKING)
	{
		if (print_status(data, data->philo[i].id_philo, "is thinking",
				C_THINK) == 1)
			return (1);
		data->philo[i].philo_status = EATING;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	try_lock(&data->mutex_n_thread);
	i = data->n_thread;
	try_unlock(&data->mutex_n_thread);
	if (data->nb_meals > 0)
	{
		while (data->philo_dead == FALSE
			&& data->nb_meals > data->philo[i].nb_eats)
		{
			if (philo_life(data, i) == 1)
				break ;
		}
	}
	else
	{
		while (data->philo_dead == FALSE)
		{
			if (philo_life(data, i) == 1)
				break ;
		}
	}
	return (NULL);
}
