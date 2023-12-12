/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:45:35 by amennad           #+#    #+#             */
/*   Updated: 2023/12/11 18:16:34 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_STRUCT_H
# define ALL_STRUCT_H

# include "philo.h"
# include <pthread.h>
typedef enum e_bool			t_bool;
typedef enum e_philo_status	t_philo_status;
typedef struct s_data		t_data;
typedef struct s_philo		t_philo;

enum						e_bool
{
	FALSE,
	TRUE
};

enum						e_philo_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
};

struct						s_philo
{
	t_data					*data;
	pthread_t				thread;
	t_bool					eating;
	size_t					start_time;
	size_t					last_meal;
	size_t					is_time_to_eat;
	int						id_philo;
	int						id_fork;
	int						start_eat;
	int						nb_eats;
	t_philo_status			philo_status;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			*r_fork;
	int						nb_forks;
};

struct						s_data
{
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	size_t					nb_philo;
	size_t					nb_meals;
	time_t					start_meat;
	t_bool					dead;
	pthread_mutex_t			*str_message;
	pthread_t *philos_thread; // Tableau de threads == de philos
	pthread_mutex_t *forks;   // Tableau de mutex == de fourchettes
};

#endif
