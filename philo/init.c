/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:34:33 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/22 16:51:43 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int				i;
	pthread_mutex_t	*print;

	i = 0;
	print = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(print, NULL) != 0
		|| pthread_mutex_init(&philo->print_mutex, NULL) != 0
		|| pthread_mutex_init(&philo->eat_mutex, NULL) != 0)
		return (1);
	while (i < data->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].start_eat = get_time();
		philo[i].is_eating = 0;
		philo[i].last_eat = get_time();
		philo[i].eat_count = 0;
		philo[i].eat_count = 0;
		philo[i].data = data;
		philo[i].forks = forks;
		philo[i].print = print;
		philo[i].eat_mutex = philo->eat_mutex;
		i++;
	}
	return (0);
}
