/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:34:45 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/23 00:55:13 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_param(t_data data, int num)
{
	if (num == 6 && data.number_must_eatt <= 0)
	{
		ft_putendl_fd("Error: number_must_eatt", 2);
		return (1);
	}
	if (data.num_philo < 0 || data.num_philo > 200)
		return (ft_putendl_fd("Error: num_philo < 0", 2), 1);
	if (data.time_to_die < 60)
		return (ft_putendl_fd("Error: time_to_die ", 2), 1);
	if (data.time_to_eat < 60)
		return (ft_putendl_fd("Error: time_to_eat ", 2), 1);
	if (data.time_to_sleep < 60)
		return (ft_putendl_fd("Error: time_to_sleep ", 2), 1);
	return (0);
}
