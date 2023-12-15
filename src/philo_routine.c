/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:48:48 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 18:44:40 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_dead(t_philo *philo)
{
	t_bool	is_dead;

	ft_try_lock(&philo->data->mutex_is_dead);
	if (philo->data->philo_dead == TRUE)
		return (TRUE);
	else if ((ft_get_time() - philo->last_meal) > philo->data->time_to_die)
	{
		philo->philo_status = DEAD;
		philo->data->philo_dead = TRUE;
		print_status(philo->data, philo->id_philo, "died", C_DEAD);
		is_dead = TRUE;
	}
	else
		is_dead = philo->data->philo_dead;
	ft_try_unlock(&philo->data->mutex_is_dead);
	return (is_dead);
}

int	take_fork(t_data *data, int i)
{
	ft_try_lock(data->philo[i]->mutex_l_fork);
	data->philo[i]->lock_l_fork = TRUE;
	if (print_status(data, data->philo[i]->id_philo, "has taken a fork",
			C_FORK) == 1)
		//todo si 1 il faut lacher la furchette
		return (1);
	ft_try_lock(data->philo[i]->mutex_r_fork);
	data->philo[i]->lock_r_fork = TRUE;
	if (print_status(data, data->philo[i]->id_philo, "has taken a fork",
			C_FORK) == 1)
		//todo si 1 il faut lacher la furchette
		return (1);
	return (0);
}

int	drop_fork(t_data *data, int i)
{
	if (data->philo[i]->lock_l_fork == TRUE)
	{
		ft_try_unlock(data->philo[i]->mutex_l_fork);
		data->philo[i]->lock_l_fork = FALSE;
	}
	if (data->philo[i]->lock_r_fork == TRUE)
	{
		ft_try_unlock(data->philo[i]->mutex_r_fork);
		data->philo[i]->lock_r_fork = FALSE;
	}
	return (0);
}

t_bool	i_m_dead(t_philo *philo)
{
	// printf("last_meal: %ld\n", philo->last_meal);
	// printf("time_to_die: %d\n", philo->time_to_die);
	// printf("ft_get_time(): %ld\n", ft_get_time());
	// printf("ft_get_time() - philo->last_meal: %ld\n", (ft_get_time()
	// 			- philo->last_meal));
	// printf("(ft_get_time() - philo->last_meal) > philo->time_to_die: %d\n",
	// 		(ft_get_time() - philo->last_meal) > philo->time_to_die);
	if ((ft_get_time() - philo->last_meal) > philo->time_to_die)
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	philo_is_dead(t_philo *philo)
{
	printf("philo_is_dead ?\n");
	ft_try_lock(&philo->data->mutex_is_dead);
	if (philo->data->philo_dead == TRUE || i_m_dead(philo) == TRUE)
	{
		printf("philo_is_dead\n");
		// printf("philo->data->philo_dead: %d\n", philo->data->philo_dead);
		// printf("i_m_dead(philo): %d\n", i_m_dead(philo));
		philo->data->philo_dead = TRUE;
		ft_try_unlock(&philo->data->mutex_is_dead);
		philo->philo_status = DEAD;
		print_status(philo->data, philo->id_philo, "died", C_DEAD);
		return (TRUE);
	}
	ft_try_unlock(&philo->data->mutex_is_dead);
	return (FALSE);
}

void *
philo_routine(void *arg)
{
	t_data	*data;
	size_t	i;

	data = (t_data *)arg;
	ft_try_lock(&data->mutex_n_philo);
	i = data->n_philo;
	ft_try_unlock(&data->mutex_n_philo);
	// while (1)
	while (philo_is_dead(data->philo[i]) == FALSE)
	{
		printf("FUCK YOU PROJET DE MERDE\n");
		if (philo_life(data,
						i) == 1)
			break ;
	}
	return (NULL);
}
