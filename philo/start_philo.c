/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:28:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/18 18:29:46 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->print);
	printf("%lu {%d} %s\n", get_time() - philo->start_eat, philo->id + 1, str);
	pthread_mutex_unlock(philo->data->print);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(150);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		pthread_mutex_lock(&philo->death);
		if(philo->data->number_of_times_each_philosopher_must_eat > 0)
			philo->data->eat_count++;
		philo->last_eat = get_time();
		ft_print(philo, "is sleeping");
		pthread_mutex_unlock(&philo->death);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		// usleep(philo->data->time_to_sleep * 1000);
		ft_print(philo, "is thinking");
	}
	return (NULL);
}

int start_thread(t_philo *philo)
{
	int i;

	i = -1;
	philo->data->thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->data->number_of_philosophers);
	while (++i < philo->data->number_of_philosophers)
	{
		if (pthread_create(&philo->data->thread[i], NULL, &routine, philo))
			return (1);
	}
	i = -1;
	while (++i < philo->data->number_of_philosophers)
	{
		if (pthread_join(philo->data->thread[i], NULL) != 0)
			return (1);
	}
	return (0);
}

int    start_philo(t_data *data, int ac, char **av)
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (ft_init(data, ac, av) || init_philo(philo, data))
	{
		ft_putendl_fd("error of initialise", 2);
		return (free(philo), 1);
	}
	start_thread(philo);
	return (0);
}