/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_vars_init_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:26:55 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 14:58:34 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// record the argv values in vars and init mutex_vars
void	vars_init(t_vars *vars, int argc, char **argv)
{
	vars->nb_philo = ft_atoi(argv[1]);
	vars->die_duration = ft_atoi(argv[2]);
	vars->eat_duration = ft_atoi(argv[3]);
	vars->sleep_duration = ft_atoi(argv[4]);
	if (argc == 6)
		vars->nb_x_eat = ft_atoi(argv[5]);
	else
		vars->nb_x_eat = -1;
	vars->philo_dead = 0;
	pthread_mutex_init(&vars->mutex_vars, NULL);
	vars->synchro_start = 0;
}

// malloc and init philo (thread, mutex, struct)
t_philo	**philo_init(t_vars *vars)
{
	int		i;
	t_philo	**philo;

	philo = (t_philo **)malloc(sizeof(t_philo *) * vars->nb_philo);
	i = -1;
	while (++i != vars->nb_philo)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		philo[i]->number = i;
		pthread_mutex_init(&philo[i]->fork, NULL);
		if (i > 0)
			philo[i]->fork2 = &philo[i - 1]->fork;
		philo[i]->done = 0;
		philo[i]->state = READY_TO_THINK;
		philo[i]->nb_x_eat = 0;
		philo[i]->vars = vars;
	}
	philo[0]->fork2 = NULL;
	if (vars->nb_philo > 1)
		philo[0]->fork2 = &philo[vars->nb_philo - 1]->fork;
	return (philo);
}

//Wait all thread & Free philo and destroy mutex
void	free_n_destroy(t_philo **philo, t_vars *vars)
{
	int	i;

	i = -1;
	while (++i != vars->nb_philo)
	{
		pthread_join(philo[i]->thread_philo, NULL);
		pthread_mutex_destroy(&philo[i]->fork);
		free(philo[i]);
	}
	free(philo);
	pthread_mutex_destroy(&vars->mutex_vars);
}
