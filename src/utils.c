/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:12 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 11:37:58 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_get_time(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}

void	ft_try_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
	{
		printf("thread lock error\n");
		exit(errno);
	}
}

void	ft_try_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
	{
		printf("thread unlock error\n");
		exit(errno);
	}
}

int	print_status(t_data *data, int id, char *str, char *color)
{
	int aff_time;

	ft_try_lock(&(data->mutex_message));
	if (data->philo_dead == TRUE)
	{
		aff_time = ft_get_time() - data->start_meal + data->time_to_die;
		printf("%s %d %d %s %s\n", C_DEAD, aff_time, id, str, C_RESET);
		ft_try_unlock(&(data->mutex_message));
		return (1);
	}
	else
	{
		aff_time = ft_get_time() - data->start_meal;
		printf("%s %d %d %s %s\n", color, aff_time, id, str, C_RESET);
	}
	ft_try_unlock(&(data->mutex_message));
	return (0);
}