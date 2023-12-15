/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:15:56 by amennad           #+#    #+#             */
/*   Updated: 2023/12/14 17:39:18 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argc_invalid(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: ");
		printf("%s[nb_philosophers] ", C_BLUE);
		printf("%s[time_to_die] ", C_DEAD);
		printf("%s[time_to_eat] ", C_EAT);
		printf("%s[time_to_sleep] ", C_SLEEP);
		printf("%s[nb_meal]%s\n", C_EAT, C_RESET);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc_invalid(argc) == 1)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (check_valid_args(argv, data) == FALSE)
	{
		return (philo_free(data, 1));
	}
	if (initialize(data) == 1)
	{
		return (philo_free(data, 1));
	}
	if (data->nb_philo == 1)
	{
		if (philo_alone(data) == 1)
			return (philo_free(data, 1));
		return (philo_free(data, 0));
	}
	if (the_meal(data) == 1)
		return (philo_free(data, 1));
	return (philo_free(data, 0));
}
