
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
time_t	ft_get_time(void);
void	try_unlock(pthread_mutex_t *mutex);
void	try_lock(pthread_mutex_t *mutex);
int		destroy_threads(t_data *data);
int		philo_free(t_data *data, int ret);
int		print_status(t_data *data, int id, char *str, char *color);

// ALGO
t_bool	check_args(char *str, size_t *data_item, char *message);
t_bool	check_valid_args(char *argv[], t_data *data);
int		initialize(t_data *data);
int		philo_alone(t_data *data);
int		the_meal(t_data *data);
void	*routine(void *arg);
void	*is_dead(void *arg);

#endif
