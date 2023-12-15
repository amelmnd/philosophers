/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:14:51 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 11:38:31 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_data *data, size_t i)
{
	if (take_fork(data, i) == 1)
		return (1);
	if (print_status(data, data->philo[i]->id_philo, "is eating", C_EAT) == 1)
		return (1);
	data->philo[i]->last_meal = ft_get_time();
	usleep(data->time_to_eat * 1000);
	if (drop_fork(data, i) == 1)
		return (1);
	data->philo[i]->nb_eats++;
	data->philo[i]->philo_status = SLEEPING;
	return (0);
}

int	philo_sleep(t_data *data, size_t i)
{
	if (print_status(data, data->philo[i]->id_philo, "is sleeping",
			C_SLEEP) == 1)
		return (1);
	usleep(data->time_to_sleep * 1000);
	data->philo[i]->philo_status = THINKING;
	return (0);
}

int	philo_think(t_data *data, size_t i)
{
	if (print_status(data, data->philo[i]->id_philo, "is thinking",
			C_THINK) == 1)
		return (1);
	data->philo[i]->philo_status = EATING;
	usleep(data->time_to_eat / 4 * 1000);
	return (0);
}

int	philo_life(t_data *data, size_t i)
{
	// if (check_dead(data->philo[i]) == FALSE)
	// 	return (1);
	if (data->philo[i]->philo_status == EATING)
	{
		printf("philo[%zu]->philo_status == EATING\n", i);
		if (philo_eat(data, i) == 1)
			return (1);
	}
	if (data->philo[i]->philo_status == SLEEPING)
	{
		printf("philo[%zu]->philo_status == SLEEPING\n", i);
		if (philo_sleep(data, i) == 1)
			return (1);
	}
	if (data->philo[i]->philo_status == THINKING)
	{
		printf("philo[%zu]->philo_status == THINKING\n", i);
		if (philo_think(data, i) == 1)
			return (1);
	}
	return (0);
}
