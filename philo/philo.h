/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:19:59 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/17 11:22:03 by hamaarou         ###   ########.fr       */
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
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}					t_data;

typedef struct s_philo
{
	int	id;
	size_t	start_eat;
	size_t	last_eat;
	pthread_mutex_t	death;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data	*data;
}	t_philo;
 
 
// +++++ init +++++
int		start_philo(t_data *data, int ac, char **av);

// +++++ utils +++++
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
# endif
