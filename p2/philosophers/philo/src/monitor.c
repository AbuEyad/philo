/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 00:53:57 by habu-zua           #+#    #+#             */
/*   Updated: 2021/06/29 17:54:28 by habu-zua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_each_must_eat(void *argv)
{
	t_info	*info;

	info = argv;
	while (!info->finish)
	{
		pthread_mutex_lock(&info->finish_mutex);
		if (info->num_of_eat_finish_philo == info->num_of_philo)
			info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
	}
	return (NULL);
}

void	*monitor(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

	philo = argv;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->info->finish_mutex);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_time_to_eat);
		gettimeofday(&now, NULL);
		if (ms >= philo->info->time_to_die && philo->info->finish == 0)
		{
			printf("%lld\t%d\t %s\n", \
				time_to_ms(now) - time_to_ms(philo->info->create_at), \
				philo->n + 1, "died");
			philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	return (NULL);
}
