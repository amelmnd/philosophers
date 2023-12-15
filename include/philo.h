/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:15:02 by amennad           #+#    #+#             */
/*   Updated: 2023/12/15 17:11:45 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "all_struc.h"
// selon les besoins du projet, ajouter les includes nécessaires
# include <errno.h>
# include <pthread.h>  //for threads
# include <stdio.h>    //for printf
# include <stdlib.h>   //for malloc
# include <sys/time.h> //for gettimeofday
# include <unistd.h>
# include <unistd.h> //for usleep

# define C_DEAD "\e[1;31m"
# define C_SLEEP "\e[1;33m"
# define C_THINK "\e[1;34m"
# define C_FORK "\e[1;37m"
# define C_EAT "\e[1;35m"
# define C_BLUE "\e[1;36m"
# define C_RESET "\e[0m"

// UTILS
int		philo_atoi(char *str);
time_t	ft_get_time(void);
void	ft_try_unlock(pthread_mutex_t *mutex);
void	ft_try_lock(pthread_mutex_t *mutex);
int		print_status(t_data *data, int id, char *str, char *color);
int		free_destroy(t_data *data, t_bool error);

// PARSING
t_bool	argc_is_valid(int argc);
t_bool	argv_is_valid(char *argv[]);
t_bool	arg_is_valid(char *str, char *message);

// INIT
int		initialize(char *argv[], t_data *data);
int		init_data(t_data *data, char *argv[]);
int		the_meal(t_data *data);

// ALGO
int		drop_fork(t_data *data, int i);
int		take_fork(t_data *data, int i);
t_bool	check_dead(t_philo *philo);
void	*philo_routine(void *arg);
int		philo_life(t_data *data, size_t i);
t_bool	philo_is_dead(t_philo *philo);

#endif
