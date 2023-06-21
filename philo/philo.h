/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:19:59 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/21 21:58:54 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			number_must_eatt;
}					t_data;

typedef struct s_philo
{
	struct s_philo	*phil;
	int				id;
	size_t			start_eat;
	size_t			last_eat;
	int				is_eating;
	size_t			eat_count;
	pthread_t		thread;
	pthread_mutex_t	death;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
	t_data			*data;
}					t_philo;
// +++++ Check +++++
int		check_param(t_data philo, int num);
// +++++ init +++++
int		ft_init(t_philo *philo, t_data *data, pthread_mutex_t *forks);
// +++++ Start +++++
int		start_philo(t_philo *philo, t_data *data, pthread_mutex_t *forks);
// +++++ Utils +++++
long	get_time(void);
void	ft_getsleep(long time);
// +++++ utils-functions +++++
int		ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	*routine(void *arg);
#endif
