/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:45:35 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 16:21:56 by amennad          ###   ########.fr       */
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

struct						s_data
{
	int						nb_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						nb_meals;
	time_t						start_meal;
	int						nb_philo_ready;
	pthread_mutex_t			mutex_philo_ready;
	int						nb_philo_finished;
	pthread_mutex_t			mutex_philo_finished;
	pthread_mutex_t			mutex_message;
	pthread_t				thread_monitoring;
	t_bool					philo_dead;
	pthread_mutex_t			mutex_is_dead;
	pthread_mutex_t			*mutex_forks;
	t_philo					**philo;
	int						n_philo;
	pthread_mutex_t			mutex_n_philo;
};

struct						s_philo
{
	t_data					*data;
	int						nb_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						nb_meals;
	time_t						start_meal;
	pthread_t				thread_philo;
	int						id_philo;
	time_t					last_meal;
	int					nb_eats;
	t_philo_status			philo_status;
	pthread_mutex_t			*mutex_l_fork;
	t_bool					lock_l_fork;
	pthread_mutex_t			*mutex_r_fork;
	t_bool					lock_r_fork;
};

#endif
