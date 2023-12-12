/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:15:56 by amennad           #+#    #+#             */
/*   Updated: 2023/12/12 09:51:10 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos_thread[i], NULL);
		i++;
	}
	while (data->nb_philo--)
	{
		pthread_mutex_destroy(data->forks);
		pthread_detach(*data->philos_thread);
	}
}

int	main(int argc, char *argv[])
{
	t_data *data;

	if (argc < 5 || argc > 6)
	{
		printf("Error: %s[nb_philosophers] %s[time_to_die] %s[time_to_eat] ",
				C_BLUE,
				C_DEAD,
				C_EAT);
		printf("%s[time_to_sleep] %s[nb_meat]\n", C_SLEEP, C_EAT);
		return (1);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (check_valid_args(argv, data) == FALSE)
		return (1);

	t_philo *philos = (t_philo *)malloc(data->nb_philo * sizeof(t_philo));

	initialize(data, philos);

	cleanup(data);
	return (0);
}