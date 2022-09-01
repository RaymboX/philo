/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:02 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/01 15:27:04 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philo_routine(t_vars *vars)
{
	int	philo_num;

	philo_init(vars, &philo_num);
	while (vars->philo[philo_num]->done == 0 && vars->philo_dead == 0)
	{
		if (vars->philo[philo_num]->state == 2)
			philo_sleep(vars, philo_num);
		philo_think(vars, philo_num);
		philo_eat(vars, philo_num);
	}
}

void	philo_init(t_vars *vars, int *philo_num)
{
	pthread_mutex_lock(&vars->mutex_i_philo);
	vars->i_philo += 1;
	*philo_num = vars->i_philo;
	pthread_mutex_unlock(&vars->mutex_i_philo);
	vars->philo[*philo_num]->fork[0] = *philo_num - 1;
	if (*philo_num == vars->nb_philo)
		vars->philo[*philo_num]->fork[1] = 0;
	else
		vars->philo[*philo_num]->fork[1] = *philo_num;
	vars->philo[*philo_num]->done = 0;
	vars->philo[*philo_num]->state = 0;
	vars->philo[*philo_num]->nb_x_eat = 0;
	if (*philo_num % 2 == 0)
	{
		philo_think(vars, philo_num);
		ft_msleep(1000);
	}
}

void	state_message(t_vars *vars, int philo_num, char *message)
{
	char	*num;

	if (vars->philo_dead == 0)
	{
		num = ft_itoa((int)(now_millisecond() - vars->time_start));
		write(1, num, ft_strlen(num));
		write(1, " ", 1);
		free(num);
		num = ft_itoa(philo_num);
		write(1, num, ft_strlen(num));
		write(1, message, ft_strlen(message));
	}
}
