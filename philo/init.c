/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:34:33 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/18 18:17:19 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	initialize_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return(ft_putendl_fd("Error: mutex flaid", 2), 1);
	}
	return (0);
}
int    ft_init(t_data *data, int ac, char **av)
{
	int mutex;
	
	data->number_of_philosophers = ft_atoi(av[1]);// <= 0 > 200
	data->time_to_die = ft_atoi(av[2]);// > 60
	data->time_to_eat = ft_atoi(av[3]);// > 60
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -42;
	data->eat_count = 0;
	data->forks =(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->forks)
		return (1);
	mutex = initialize_mutex(data);
	if (mutex)
		return(ft_putendl_fd("Error in mutex init!", 2), 1);
	if (check_param(*data, ac))
		return (1);
    return (0);
}

int init_philo(t_philo *philo, t_data *data)
{
	int		i;
	size_t	time;

	i = -1;
	time = get_time();
		
	while (++i < data->number_of_philosophers)
	{	
		philo->id = i;
		philo->start_eat = time;
		philo->left_fork = &data->forks[i];
		philo->right_fork = &data->forks[(i + 1) % data->number_of_philosophers];
		philo->is_eating = 0;
		philo->last_eat = 0;
		philo->data = data;
		if (pthread_mutex_init(&philo->death, NULL) != 0)
		{
			return (1);
		}
	}
	return (0);
}