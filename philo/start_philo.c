/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:28:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/21 20:41:53 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
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
		pthread_mutex_lock(&philo->death);
		if (philo->data->number_must_eatt > 0)
			philo->eat_count++;
		philo->last_eat = get_time();
		ft_print(philo, "is sleeping");
		ft_getsleep(philo->data->time_to_sleep);
		ft_print(philo, "is thinking");
		pthread_mutex_unlock(&philo->death);
	}
	return (NULL);
}

void	check_death(t_philo *philo)
{
	unsigned long	i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		if (philo->data->number_must_eatt > 0
			&& philo->eat_count
			== philo->data->number_must_eatt)
		{
			pthread_mutex_unlock(&philo->print_mutex);
			return ;
		}
		if (get_time() - philo[i].last_eat > philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->print_mutex);
			printf("\033[0;31m%lu {%d} died\033[1;0m\n",
				get_time() - philo->start_eat, philo->id);
			pthread_mutex_unlock(&philo->print_mutex);
			return ;
		}
		i++;
		if (i == philo->data->num_philo)
			i = 0;
	}
}

int	start_thread(t_philo *philo)
{
	unsigned long	i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
			return (1);
		i++;
	}
	check_death(philo);
	return (0);
}

int	start_philo(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	if (ft_init(philo, data, forks))
	{
		ft_putendl_fd("error of initialise", 2);
		return (free(philo), 1);
	}
	start_thread(philo);
	return (0);
}
