/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:34:01 by amennad           #+#    #+#             */
/*   Updated: 2023/12/11 18:15:03 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_args(char *str, size_t *data_item, char *message)
{
	*data_item = philo_atoi(str);
	if (*data_item <= 0)
	{
		ft_printf("Error: Wrong %s\n", message);
		return (FALSE);
	}
	return (TRUE);
}

void	check_valid_args(char *argv[], t_data *data)
{
	t_bool	is_valid;

	pthread_mutex_init(&data->str_message, NULL);
	is_valid = check_args(argv[1], &data->nb_philo, "number of philo");
	if (is_valid == FALSE)
		return ;
	is_valid = check_args(argv[2], &data->time_to_die, "time to die");
	if (is_valid == FALSE)
		return ;
	is_valid = check_args(argv[3], &data->time_to_eat, "time to eat");
	if (is_valid == FALSE)
		return ;
	is_valid = check_args(argv[4], &data->time_to_sleep, "time to sleep");
	if (is_valid == FALSE)
		return ;
	if (argv[5])
	{
		is_valid = check_args(argv[5], &data->nb_meals,
				"number of times each philosopher must eat");
		if (is_valid == FALSE)
			return ;
	}
}

int	main(int argc, char *argv[])
{
	t_data			data;
	pthread_mutex_t	mutex;

	data = (t_data){0, 0, 0, 0, 0};
	if (argc < 5 || argc > 6)
	{
		ft_printf("Error: number of arguments\n");
		return (1);
	}
	check_valid_args(argv, &data);
	if (data.nb_philo == 0 || data.time_to_die == 0 || data.time_to_eat == 0
		|| data.time_to_sleep == 0)
		return (1);
	pthread_mutex_init(&mutex, NULL);
}
