/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:19:48 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/22 16:51:27 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data **data, int ac, char **av)
{
	(*data)->num_philo = ft_atoi(av[1]);
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->number_must_eatt = ft_atoi(av[5]);
	else
		(*data)->number_must_eatt = -42;
	if (check_param(*(*data), ac))
		return (1);
	return (0);
}

void	init_mutex(pthread_mutex_t *forks, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			ft_putendl_fd("Error: mutex flaid", 2);
		i++;
	}
}

void	main_destroy(t_philo *philo, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philo->death);
		pthread_mutex_destroy(&philo->print_mutex);
		i++;
	}
	free(philo);
	free(data);
	free(forks);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_data			*data;
	pthread_mutex_t	*forks;

	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Error: bad arguments", 2), 1);
	data = malloc(sizeof(t_data));
	if (init_data(&data, ac, av) == 1)
		return (printf("Error: bad arguments\n"), 1);
	forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	init_mutex(forks, data);
	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		return (ft_putendl_fd("Error: malloc failed", 2), 1);
	if (start_philo(philo, data, forks) == 1)
		return (ft_putendl_fd("Error: bad arguments", 2), 1);
	return (0);
}
