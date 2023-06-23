/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:08:24 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/23 01:08:46 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	(void)str;
	pthread_mutex_lock(philo->print);
	printf("%lu {%d} %s\n", get_time() - philo->start_eat, philo->id, str);
	pthread_mutex_unlock(philo->print);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->id - 1]);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->forks[philo->id % philo->data->num_philo]);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		ft_getsleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->forks[philo->id % philo->data->num_philo]);
		pthread_mutex_unlock(&philo->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->data->number_must_eatt > 0)
			philo->eat_count++;
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_print(philo, "is sleeping");
		ft_getsleep(philo->data->time_to_sleep);
		ft_print(philo, "is thinking");
	}
	return (NULL);
}
