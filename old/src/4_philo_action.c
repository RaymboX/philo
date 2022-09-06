/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_philo_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:07 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/06 10:17:22 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philo_eat(t_vars *vars, int philo_num)
{
	pthread_mutex_lock(vars->fork[vars->philo[philo_num]->fork[0]]);
	state_message(vars, philo_num, MESSAGE_FORK);
	pthread_mutex_lock(vars->fork[vars->philo[philo_num]->fork[1]]);
	vars->philo[philo_num]->time_eat = now_millisecond();
	ft_msleep(vars->eat_duration);
	pthread_mutex_unlock(vars->fork[vars->philo[philo_num]->fork[0]]);
	pthread_mutex_unlock(vars->fork[vars->philo[philo_num]->fork[1]]);
	state_message(vars, philo_num, MESSAGE_EAT);
	vars->philo[philo_num]->state = 2;
	vars->philo[philo_num]->nb_x_eat += 1;
	if ((int)vars->philo[philo_num]->nb_x_eat >= vars->nb_x_eat)
			vars->philo[philo_num]->done = 1;
}

void	philo_sleep(t_vars *vars, int philo_num)
{
	state_message(vars, philo_num, MESSAGE_SLEEP);
	ft_msleep(vars->sleep_duration);
	vars->philo[philo_num]->state = 0;
}

void	philo_die(t_vars *vars, int philo_num)
{
	state_message(vars, philo_num, MESSAGE_DIE);
	vars->philo_dead = 1;
}

void	philo_think(t_vars *vars, int philo_num)
{
	if (vars->philo[philo_num]->state == 0)
		state_message(vars, philo_num, MESSAGE_THINK);
	vars->philo[philo_num]->state = 1;
}
