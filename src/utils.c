/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:56:21 by amennad           #+#    #+#             */
/*   Updated: 2023/12/14 17:39:18 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_get_time(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}

void	try_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
	{
		printf("thread lock error\n");
		exit(EXIT_FAILURE);
	}
}

int	print_status(t_data *data, int id, char *str, char *color)
{
	size_t aff_time;
	try_lock(&(data->str_message));
	if (data->philo_dead == TRUE)
	{
		aff_time = ft_get_time() - data->start_meal + data->time_to_die;
		printf("%s %ld %d %s %s\n", C_DEAD, aff_time, id, str, C_RESET);
		try_unlock(&(data->str_message));
		return (1);
	}
	else
	{
		aff_time = ft_get_time() - data->start_meal;
		printf("%s %ld %d %s %s\n", color, aff_time, id, str, C_RESET);
	}
	try_unlock(&(data->str_message));
	return (0);
}