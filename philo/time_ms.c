/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:33:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/23 00:25:47 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_getsleep(long time)
{
	long	begin;

	begin = get_time();
	while (get_time() - begin < time)
		usleep(150);
}

void	array_of_ints(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}

int	global_eat(int *arr, int n)
{
	int	i;

	i = 0;
	while (arr[i] == 1)
		i++;
	if (i == n)
		return (1);
	return (0);
}
