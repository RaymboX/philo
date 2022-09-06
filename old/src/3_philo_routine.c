/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:02 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/06 11:12:52 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philo_routine(void *void_vars)
{
	t_vars	*vars;
	int		philo_num;

	vars = (t_vars *)void_vars;
	philo_init(vars, &philo_num);
	while (vars->philo[philo_num]->done == 0 && vars->philo_dead == 0)
	{
		if (vars->philo[philo_num]->state == 2)
			philo_sleep(vars, philo_num);
		philo_think(vars, philo_num);
		philo_eat(vars, philo_num);
	}
	pthread_mutex_lock(&vars->mutex_terminal);
	write_int(philo_num);
	write(1, " done\n", 6);
	pthread_mutex_unlock(&vars->mutex_terminal);
	return (NULL);
}

void	philo_init(t_vars *vars, int *philo_num)
{
	pthread_mutex_lock(&vars->mutex_i_philo);
	*philo_num = vars->i_philo;
	vars->i_philo += 1;
	pthread_mutex_unlock(&vars->mutex_i_philo);
	vars->philo[*philo_num]->fork[0] = *philo_num - 1;
	if (*philo_num == vars->nb_philo)
		vars->philo[*philo_num]->fork[1] = 0;
	else
		vars->philo[*philo_num]->fork[1] = *philo_num;
	vars->philo[*philo_num]->done = 0;
	vars->philo[*philo_num]->state = 0;
	vars->philo[*philo_num]->nb_x_eat = 0;
	//vars->philo[*philo_num]->time_eat = now_millisecond();
	synchro_start_relay(vars);
	if (*philo_num % 2 == 1)
	{
		philo_think(vars, *philo_num);
		usleep(vars->eat_duration / 2);
	}
	else
		vars->philo[*philo_num]->state = 1;
}

void	state_message(t_vars *vars, int philo_num, char *message)
{
	//char	*str_time;
	//char	*str_philo;

	if (vars->philo_dead == 0)
	{
	/*	
		str_time = ft_itoa((int)(now_millisecond() - vars->time_start));
		str_philo = ft_itoa(philo_num + 1);
		pthread_mutex_lock(&vars->mutex_terminal);
		write(1, str_time, ft_strlen(str_time));
		write(1, " ", 1);
		write(1, str_philo, ft_strlen(str_philo));
		write(1, message, ft_strlen(message));
		pthread_mutex_unlock(&vars->mutex_terminal);
		free(str_time);
		free(str_philo);
		*/
		printf("%d %d %s", (int)(now_millisecond() - vars->time_start),
			philo_num + 1, message);
	}
}
