/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:00:16 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 14:54:03 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_philo	**philo;

	if (arg_parcing(argc, argv) != 0)
		return (1);
	vars_init(&vars, argc, argv);
	philo = philo_init(&vars);
	create_philo_thread(&vars, philo);
	dead_n_eat_checker(&vars, philo);
	free_n_destroy(philo, &vars);
	return (0);
}

//creating the philo thread
void	create_philo_thread(t_vars *vars, t_philo **philo)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&vars->mutex_vars);
	while (++i < vars->nb_philo)
		pthread_create(&philo[i]->thread_philo, NULL,
			&philo_routine, (void *)philo[i]);
	pthread_mutex_unlock(&vars->mutex_vars);
	while (vars->synchro_start != 1)
		usleep(50);
	pthread_mutex_lock(&vars->mutex_vars);
	vars->time_start = now_millisecond();
	i = -1;
	while (++i < vars->nb_philo)
		philo[i]->last_eat = vars->time_start;
	vars->synchro_start = 2;
	pthread_mutex_unlock(&vars->mutex_vars);
}

//Check if one philo dead or if everybody done eating
void	dead_n_eat_checker(t_vars *vars, t_philo **philo)
{
	while (dead_checker(vars, philo) == 0 && done_checker(vars, philo) == 0)
		usleep(50);
}

//Check all philo to know if someone dead
int	dead_checker(t_vars *vars, t_philo **philo)
{
	int	i;

	i = 0;
	while (i != vars->nb_philo)
	{
		if (philo[i]->done == 0 && (int)(now_millisecond() - philo[i]->last_eat)
			> vars->die_duration)
		{
			pthread_mutex_lock(&vars->mutex_vars);
			vars->philo_dead = 1;
			printf("%d %d %s", (int)(now_millisecond() - vars->time_start),
				i + 1, MESSAGE_DIE);
			pthread_mutex_unlock(&vars->mutex_vars);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

//Check if all philo finish eating
int	done_checker(t_vars *vars, t_philo **philo)
{
	int	i;
	int	nb_done;

	nb_done = 0;
	i = -1;
	while (++i != vars->nb_philo)
	{
		if (philo[i]->done == 1)
			nb_done += 1;
	}
	if (nb_done >= vars->nb_philo)
		return (1);
	return (0);
}
