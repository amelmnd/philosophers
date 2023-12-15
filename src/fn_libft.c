/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:27:12 by amennad           #+#    #+#             */
/*   Updated: 2023/12/14 11:27:16 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	philo_atoi(char *str)
{
	int i;
	int result;

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