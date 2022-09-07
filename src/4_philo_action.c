/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_philo_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:07 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 15:02:18 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

//Eating procedure 
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
		philo->state = READY_TO_SLEEP;
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

//sleeping procedure
void	philo_sleep(t_philo *philo)
{
	state_message(philo->vars, philo->number, MESSAGE_SLEEP);
	ft_msleep(philo->vars->sleep_duration);
	philo->state = READY_TO_THINK;
}

//thinking procedure
void	philo_think(t_philo *philo)
{
	if (philo->state == READY_TO_THINK)
		state_message(philo->vars, philo->number, MESSAGE_THINK);
	philo->state = READY_TO_EAT;
}
