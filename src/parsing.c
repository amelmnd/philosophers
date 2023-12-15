/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:23:57 by amennad           #+#    #+#             */
/*   Updated: 2023/12/12 10:12:08 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result + (str[i] - 48);
		i++;
		if (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
			result = result * 10;
		if (result > 2147483647)
			return (-1);
	}
	return (result);
}

t_bool	check_args(char *str, size_t *data_item, char *message)
{
	*data_item = philo_atoi(str);
	if (*data_item <= 0)
	{
		printf("Error: number cannot be 0 %s\n", message);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_valid_args(char *argv[], t_data *data)
{
	t_bool	is_valid;

	is_valid = check_args(argv[1], &data->nb_philo, "number of philo");
	if (is_valid == FALSE)
		return (FALSE);
	is_valid = check_args(argv[2], &data->time_to_die, "time to die");
	if (is_valid == FALSE)
		return (FALSE);
	is_valid = check_args(argv[3], &data->time_to_eat, "time to eat");
	if (is_valid == FALSE)
		return (FALSE);
	is_valid = check_args(argv[4], &data->time_to_sleep, "time to sleep");
	if (is_valid == FALSE)
		return (FALSE);
	if (argv[5])
	{
		is_valid = check_args(argv[5], &data->nb_meals,
				"number of times each philosopher must eat");
		if (is_valid == FALSE)
			return (FALSE);
	}
	if (data->nb_philo == 0 || data->time_to_die == 0 || data->time_to_eat == 0
		|| data->time_to_sleep == 0)
		return (FALSE);
	return (TRUE);
}
