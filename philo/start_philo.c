/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:28:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/23 01:28:10 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death(t_philo *philo, int i)
{
	if (get_time() - (long)philo[i].last_eat
		> (long)philo->data->time_to_die)
	{
		pthread_mutex_lock(philo[i].print);
		printf("\033[0;31m%lu {%d} died\033[1;0m\n",
			get_time() - philo->start_eat, philo->id);
		return (1);
	}
	return (0);
}

void	check_death(t_philo *philo)
{
	int	i;
	int	arr[255];

	i = 0;
	array_of_ints(arr, philo->data->num_philo);
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(&philo[i].eat_mutex);
		if (philo->data->number_must_eatt > 0 && philo[i].eat_count
			>= (size_t)philo->data->number_must_eatt)
		{
			arr[i] = 1;
			if (global_eat(arr, philo->data->num_philo))
				return ;
		}
		if (death(philo, i))
			return ;
		i++;
		if (i == philo->data->num_philo)
			i = 0;
		pthread_mutex_unlock(&philo[i].eat_mutex);
	}
}

int	start_thread(t_philo *philo)
{
	int	i;

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
