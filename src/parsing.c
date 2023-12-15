/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:23:57 by amennad           #+#    #+#             */
/*   Updated: 2023/12/14 17:39:54 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	argc_is_valid(int argc) // <--- ✅
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: ");
		printf("%s[nb_philosophers] ", C_BLUE);
		printf("%s[time_to_die] ", C_DEAD);
		printf("%s[time_to_eat] ", C_EAT);
		printf("%s[time_to_sleep] ", C_SLEEP);
		printf("%s[nb_meal]%s\n", C_EAT, C_RESET);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	arg_is_valid(char *str, char *message) // <--- ✅
{
	if (philo_atoi(str) == 0)
	{
		printf("Error: %s cannot be 0\n", message);
		return (FALSE);
	}
	else if (philo_atoi(str) == -1)
	{
		printf("Error: invalid %s\n", message);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	argv_is_valid(char *argv[]) // <--- ✅
{
	t_bool is_valid;

	is_valid = arg_is_valid(argv[1], "number of philo");
	if (is_valid == FALSE || philo_atoi(argv[1]) > 200)
	{
		if (philo_atoi(argv[1]) > 200)
			printf("Error: number of philosophers must be <= 200\n");
		return (FALSE);
	}
	is_valid = arg_is_valid(argv[2], "time to die");
	if (is_valid == FALSE)
		return (FALSE);
	is_valid = arg_is_valid(argv[3], "time to eat");
	if (is_valid == FALSE)
		return (FALSE);
	is_valid = arg_is_valid(argv[4], "time to sleep");
	if (is_valid == FALSE)
		return (FALSE);
	if (argv[5])
	{
		is_valid = arg_is_valid(argv[5], "number of meal per philosopher");
		if (is_valid == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
