/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:51:10 by amennad           #+#    #+#             */
/*   Updated: 2023/12/11 18:52:21 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_alone(t_data *data, t_philo *philo)
{
	philo->philo_status = DEAD;
	philo->data->dead = TRUE;
	try_lock(philo->l_fork);
	// try_lock(data->str_message); // TODO PB SEGFAULT SI ACTIVÉ
	printf("%s %d %d has taken a fork\n", C_EAT, 0, philo->id_philo);
	printf("%s %ld %d died\n", C_DEAD, data->time_to_die, philo->id_philo);
	try_unlock(philo->l_fork);
	// try_unlock(data->str_message);
}

t_bool
philo_dead(t_philo *philo)
{
	philo->philo_status = DEAD;
	philo->data->dead = TRUE;
	if (philo->nb_forks > 0)
	{
		try_unlock(philo->l_fork);
		if (philo->nb_forks > 1)
			try_unlock(philo->r_fork);
		printf("%s %ld %d died\n", C_DEAD, ft_time() - philo->data->start_meat,
				philo->id_philo);
	}
	return (TRUE);
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)arg;
	data = philo->data;

	while (data->dead == FALSE)
	{
		if (data->dead || philo->philo_status == DEAD)
			break ;
		if (philo->data->nb_philo == 1)
		{
			philo_alone(data, philo);
			break ;
		}
		// 		printf("%ld %d has taken a fork\n", start.tv_usec,
		// philo->id_philo);
		// 		philo->start_eat = start.tv_usec;
		//
		// 		// Prendre la fourchette à gauche
		// 		pthread_mutex_lock(philo->l_fork);
		// 		end.tv_usec = start.tv_usec + philo->data->time_to_eat;
		// 		if (end.tv_usec - start.tv_usec > philo->data->time_to_die)
		// 		{
		// 			philo->philo_status = DEAD;
		// 			philo->data->dead = TRUE;
		// 			break ;
		// 		}
		// 		philo->philo_status = EATING;
		// 		philo->nb_eats++;
		// 		philo->last_meal = end.tv_usec;
		// 		printf("%ld %d is eating\n", start.tv_usec, philo->id_philo);

		// 		pthread_mutex_unlock(philo->l_fork);
		// 		pthread_mutex_unlock(philo->r_fork);

		// 		// Dormir
		// 		philo->philo_status = SLEEPING;
		// 		printf("%ld %d is sleeping\n", end.tv_usec, philo->id_philo);
		// 		usleep(philo->data->time_to_sleep);
		// 		// Pensée

		// 		philo->philo_status = THINKING;
		// 		printf("%ld %d is thinking\n", (end.tv_usec
		// 					+ philo->data->time_to_sleep), philo->id_philo);
		// 		if (philo->nb_eats == philo->data->nb_meals)
		// 			break ;
		// 	}
		// 	if (philo->data->dead)
		// 	{
		// 		usleep(10);
		// 		end.tv_usec = start.tv_usec + philo->data->time_to_die;
		// 		printf("%ld %d died\n", end.tv_usec, philo->id_philo);
	}
	return (NULL);
}