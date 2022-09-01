/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:00:16 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/01 15:16:51 by mraymond         ###   ########.fr       */
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
		pthread_create(vars->philo[vars->i_philo], NULL, &philo_routine, vars);
	vars->time_start = now_millisecond();
	pthread_mutex_unlock(&vars->mutex_i_philo);
}

//Check if one philo dead or if everybody done eating
void	dead_n_eat_checker(t_vars *vars)
{
	int	i;
	int	loop;

	loop = 1;
	while (loop)
	{
		vars->nb_done == 0;
		i = -1;
		while (++i != vars->nb_philo)
		{
			if (now_millisecond() - vars->philo[i]->time_eat
				> vars->eat_duration
				&& vars->philo[i]->done != 1)
			{
				die_routine(vars);
				loop = 0;
			}
			else if (vars->philo[i]->done == 1)
				vars->nb_done += 1;
		}
		if (vars->nb_done == vars->nb_philo)
			loop = 0;
	}
}

void	join_philo_thread(t_vars *vars)
{
	vars->i_philo = -1;
	while (++vars->i_philo != vars->nb_philo)
		pthread_join(vars->philo[vars->i_philo], NULL);
}
