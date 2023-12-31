/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:28:47 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/19 14:28:49 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_forks(ph);
	pthread_mutex_lock(ph->right_fork);
	print_forks(ph);
}

void	go_to_sleep(t_philo *ph)
{
	print_sleeping(ph);
	ft_usleep(ph->table->time_to_sleep);
	ph->eat_count++;
}

void	leave_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	go_to_sleep(ph);
}
