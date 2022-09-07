/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:02 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 11:47:00 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philo_routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	philo_delay(philo);
	while (philo->done == 0 && philo->vars->philo_dead == 0)
	{
		if (philo->state == 2)
			philo_sleep(philo);
		philo_think(philo);
		philo_eat(philo);
	}
	philo_think(philo);
	return (NULL);
}

void	philo_delay(t_philo *philo)
{
	if (philo->number + 1 == philo->vars->nb_philo)
	{
		pthread_mutex_lock(&philo->vars->mutex_vars);
		philo->vars->synchro_start = 1;
		pthread_mutex_unlock(&philo->vars->mutex_vars);
	}
	while (philo->vars->synchro_start != 2)
		usleep(50);
	if (philo->number % 2 == 1)
	{
		philo_think(philo);
		ft_msleep(philo->vars->eat_duration / 2);
	}
	else
		philo->state = 1;
}

void	state_message(t_vars *vars, int philo_num, char *message)
{
	if (vars->philo_dead == 0)
		printf("%d %d %s", (int)(now_millisecond() - vars->time_start),
			philo_num + 1, message);
}
