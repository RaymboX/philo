/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:00:16 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/06 10:54:09 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (arg_parcing(argc, argv) != 0)
		return (1);
	record_arg_val_in_vars(&vars, argc, argv);
	vars_init(&vars);
	create_philo_thread(&vars);
	dead_n_eat_checker(&vars);
	join_philo_thread(&vars);
	vars_free(&vars);
	return (0);
}

//creating the philo thread
void	create_philo_thread(t_vars *vars)
{
	vars->i_philo = -1;
	pthread_mutex_lock(&vars->mutex_i_philo);
	while (++vars->i_philo != vars->nb_philo)
	{
		pthread_create(vars->thread_philo[vars->i_philo], NULL,
			&philo_routine, vars);
	}
	write(1, "all thread created\n", 19);
	vars->i_philo = 0;
	pthread_mutex_unlock(&vars->mutex_i_philo);
	synchro_start_trigger(vars);
}

//Check if one philo dead or if everybody done eating
void	dead_n_eat_checker(t_vars *vars)
{
	while (dead_checker(vars) == 0 && done_checker(vars) == 0)
		usleep(5);
}

int	dead_checker(t_vars *vars)
{
	int	i;

	i = 0;
	while (i != vars->nb_philo)
	{
		if ((int)(now_millisecond() - vars->philo[i]->time_eat)
			> vars->die_duration
			&& vars->philo[i]->done != 1)
		{
			philo_die(vars, i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	done_checker(t_vars *vars)
{
	int	i;

	vars->nb_done = 0;
	i = -1;
	while (++i != vars->nb_philo)
	{
		if (vars->philo[i]->done == 1)
			vars->nb_done += 1;
	}
	if (vars->nb_done >= vars->nb_philo)
		return (1);
	return (0);
}

void	join_philo_thread(t_vars *vars)
{
	vars->i_philo = -1;
	while (++vars->i_philo != vars->nb_philo)
		pthread_join(*vars->thread_philo[vars->i_philo], NULL);
}

void	synchro_start_trigger(t_vars *vars)
{
	int	i;
	int	wait;

	wait = 2000;
	ft_msleep(wait);
	while (vars->i_philo != vars->nb_philo)
	{
		ft_msleep(1);
		vars->time_start += 1;
	}
	i = -1;
	vars->time_start = now_millisecond();
	while (i++ != vars->nb_philo)
		vars->philo[i]->time_eat = now_millisecond();
	vars->start_enabled = 1;
}

void	synchro_start_relay(t_vars *vars)
{
	while (vars->start_enabled == 0)
		usleep(50);
}
