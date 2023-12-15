/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead_alive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:21:13 by amennad           #+#    #+#             */
/*   Updated: 2023/12/13 17:45:39 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// t_bool	check_dead(t_data *data)
// {
// 	t_bool	is_dead;

// 	pthread_mutex_lock(data->is_dead);
// 	data->philo_dead = TRUE;
// 	pthread_mutex_unlock(data->is_dead);
// 	return (isdead);
// }

int	check_philo_dead(t_data *data, size_t *i)
{
	size_t	time_last_eat;

	if (*i == data->nb_philo)
		*i = 0;
	time_last_eat = ft_get_time() - data->philo[*i].last_meal;
	if (time_last_eat > data->time_to_die)
	{
		try_lock(data->is_dead);
		data->philo->philo_status = DEAD;
		data->philo_dead = TRUE;
		try_unlock(data->is_dead);
		print_status(data, data->philo[*i].id_philo, "died", C_DEAD);
		exit(EXIT_FAILURE);
	}
	try_unlock(data->is_dead);
	i++;
	return (0);
}

void	*is_dead(void *arg)
{
	t_data *data;
	size_t i;

	data = (t_data *)arg;
	i = 0;
	if (data->nb_meals > 0)
	{
		while ((data->philo_dead == 0)
			&& (data->nb_meals > data->philo[i].nb_eats))
		{
			if (check_philo_dead(data, &i) == 1)
				break ;
		}
	}
	else
	{
		while (data->philo_dead == 0)
		{
			if (check_philo_dead(data, &i) == 1)
				break ;
		}
	}
	return (NULL);
}