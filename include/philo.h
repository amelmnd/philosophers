
#ifndef PHILO_H
# define PHILO_H

# include "all_struc.h"
# include "for_dev.h"
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
time_t	ft_time(void);
void	try_unlock(pthread_mutex_t *mutex);
void	try_lock(pthread_mutex_t *mutex);

// ALGO
t_bool	check_args(char *str, size_t *data_item, char *message);
t_bool	check_valid_args(char *argv[], t_data *data);
void	initialize(t_data *data, t_philo *philos);
void	*routine(void *arg);

#endif
