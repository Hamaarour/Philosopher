/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:34:45 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/18 13:16:50 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_param(t_data data, int num)
{
	if (data.number_of_philosophers < 0)
		return (ft_putendl_fd("Error: number_of_philosophers < 0", 2), 1);
	if (data.time_to_die < 60)
		return (ft_putendl_fd("Error: time_to_die ", 2), 1);
	if (data.time_to_eat < 60)
		return (ft_putendl_fd("Error: time_to_eat ", 2), 1);
	if (data.time_to_sleep < 60)
		return (ft_putendl_fd("Error: time_to_sleep ", 2), 1);
	if (num == 6 && data.number_of_times_each_philosopher_must_eat < 0 )
		return (ft_putendl_fd("Error: number_of_times_each_philosopher_must_eat", 2), 1);
	return (0);
}