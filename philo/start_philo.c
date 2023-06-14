/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:28:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/11 09:47:40 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_param(t_philo *philo)
{
	if ((philo->number_of_philosophers <= 0 || philo->number_of_philosophers > 200) || 
			(philo->time_to_die > 60) || (philo->time_to_eat > 60) || (philo->time_to_sleep > 60))
		return (1);
	return (0);
}

int    ft_init(t_philo *philo, int ac, char **av)
{
	philo->number_of_philosophers = ft_atoi(av[1]);// <= 0 > 200
	philo->time_to_die = ft_atoi(av[2]);// > 60
	philo->time_to_eat = ft_atoi(av[3]);// > 60
	philo->time_to_sleep = ft_atoi(av[4]); // > 60
	if (ac == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		philo->number_of_times_each_philosopher_must_eat = -42;
	if (check_param(philo))
		return (1);
	return (0);
	
}

int    start_philo(t_philo *philo, int ac, char **av)
{
	if (ft_init(philo, ac, av) == 0)
	{
		
	}
	return (1);
}