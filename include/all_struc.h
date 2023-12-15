/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_struc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:45:35 by amennad           #+#    #+#             */
/*   Updated: 2023/12/11 16:51:51 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_STRUCT_H
# define ALL_STRUCT_H


typedef enum e_bool			t_bool;
// typedef enum e_philo_status	t_philo_status;
typedef struct s_data		t_data;
// typedef struct s_philo		t_philo;

enum e_bool
{
	FALSE,
	TRUE
};

// enum e_philo_status
// {
// 	THINKING,
// 	EATING,
// 	SLEEPING,
// };

// struct s_philo
// {
// 	int				id_philo;
// 	int				id_forg;
// 	int				start_eat;
// 	int				forg_left;
// 	int				forg_rigth;
// 	// enum	e_status_forg;
// 	t_philo_status	philo_status;
// };

struct s_data
{

};

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t       t1;
	int             id;
	int             eat_cont;
	int             status;
	int             eating;
	uint64_t        time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_data
{
	pthread_t       *tid;
	int				nb_philo;
	int             philo_num;
	int             meals_nb;
	int		nb_eat;
	int             dead;
	int             finished;
	t_philo         *philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	u_int64_t       start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_data;


#endif
