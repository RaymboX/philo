/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_philo_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:07 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 12:05:24 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	state_message(philo->vars, philo->number, MESSAGE_FORK);
	if (philo->fork2 != NULL)
	{
		pthread_mutex_lock(philo->fork2);
		state_message(philo->vars, philo->number, MESSAGE_FORK);
		philo->last_eat = now_millisecond();
		state_message(philo->vars, philo->number, MESSAGE_EAT);
		ft_msleep(philo->vars->eat_duration);
		pthread_mutex_unlock(philo->fork2);
		pthread_mutex_unlock(&philo->fork);
		philo->state = 2;
		philo->nb_x_eat += 1;
		if (philo->vars->nb_x_eat > 0
			&& philo->nb_x_eat >= philo->vars->nb_x_eat)
			philo->done = 1;
	}
	else
	{
		while (philo->vars->philo_dead == 0)
			usleep(50);
	}
}

void	philo_sleep(t_philo *philo)
{
	state_message(philo->vars, philo->number, MESSAGE_SLEEP);
	ft_msleep(philo->vars->sleep_duration);
	philo->state = 0;
}

void	philo_think(t_philo *philo)
{
	if (philo->state == 0)
		state_message(philo->vars, philo->number, MESSAGE_THINK);
	philo->state = 1;
}
