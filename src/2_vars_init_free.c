/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_vars_init_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:26:55 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/01 15:26:57 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// record the argv values in vars
void	record_arg_val_in_vars(t_vars *vars, int argc, char **argv)
{
	vars->nb_philo = ft_atoi(argv[1]);
	vars->die_duration = ft_atoi(argv[2]);
	vars->eat_duration = ft_atoi(argv[3]);
	vars->sleep_duration = ft_atoi(argv[4]);
	if (argc == 6)
		vars->nb_x_eat = ft_atoi(argv[5]);
	else
		vars->nb_x_eat = -1;
	vars->nb_done = 0;
}

// malloc and init vars (thread, mutex, struct)
void	vars_init(t_vars *vars)
{
	vars->philo = (t_philo **)malloc(sizeof(t_philo *));
	vars->thread_philo = (pthread_t **)malloc(sizeof(pthread_t *)
			* vars->nb_philo);
	vars->fork = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
			* vars->nb_philo);
	vars->i_philo = -1;
	while (++vars->i_philo != vars->nb_philo)
	{
		vars->philo[vars->i_philo] = (t_philo *)malloc(sizeof(t_philo));
		vars->thread_philo[vars->i_philo]
			= (pthread_t *)malloc(sizeof(pthread_t));
		vars->fork[vars->i_philo]
			= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(vars->fork[vars->i_philo], NULL);
	}
}

void	vars_free(t_vars *vars)
{
	vars->i_philo = -1;
	while (++vars->i_philo != vars->nb_philo)
		pthread_mutex_destroy(vars->fork[vars->i_philo]);
	free_dbl_ptr(vars->philo);
	free_dbl_ptr(vars->thread_philo);
	free_dbl_ptr(vars->fork);
}
