/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:19:48 by hamaarou          #+#    #+#             */
/*   Updated: 2023/06/17 21:40:42 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    if (!data)
    {
        ft_putendl_fd("Error: malloc failed", 2);
        return (1);
    }
    if (ac >= 5 || ac < 7)
    {
        if (start_philo(data, ac, av) == 1)
        {
            ft_putendl_fd("Error: bad arguments", 2);
            return (1);
        }
    }
    else
        ft_putendl_fd("Error: bad arguments", 2);
    return (0);
}
