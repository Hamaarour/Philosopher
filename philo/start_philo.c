/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:28:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/17 13:56:10 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_param(t_data *philo)
{
	if ((philo->number_of_philosophers <= 0 || philo->number_of_philosophers > 200) || 
			(philo->time_to_die > 60) || (philo->time_to_eat > 60) || (philo->time_to_sleep > 60))
		return (1);
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
	mutex = init_mutex(data);// init mutex and return 1 if error else 0 
	if (mutex)
		return (1);
	if (check_param(data))
		return (1);
	return (0);
	
}
/*
	*tv_sec   : member of the time structure represents the number of seconds since 
				the Epoch (January 1, 1970)
	*ttv_usec : member represents the number of microseconds within the current second.
	*Overall:
	this function provides a simple way to obtain the current time in milliseconds 
	using the gettimeofday function and the timeval structure.
	
*/
int get_time(void)
{
	struct timeval time;// store time in sec and usec 
	gettimeofday(&time, NULL);// get time from system 
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000)); // return time in ms
}
/*
	init_philo : initialise the philo struct 
*/
int init_philo(t_philo *philo)
{
	int	i;
	int	time;

	i = -1;
	time = get_time();
	while (++i < philo->data->number_of_philosophers)
	{
		philo->id = i;
		philo->start_eat = time;
		philo->left_fork = &philo->data->forks[i];
		philo->right_fork = &philo->data->forks[(i + 1) % philo->data->number_of_philosophers];
		philo->data = &philo->data;
		philo->last_eat = time;
		if (pthread_mutex_init(&philo->death, NULL) != 0)
			return (1);
	}
	return (0);
}

int    start_philo(t_data *data, int ac, char **av)
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (ft_init(data, ac, av) == 0)
	{
		if (init_philo(philo))
			return (ft_putendl_fd("error of initialise", 2),1);
	}
	return (1);
}