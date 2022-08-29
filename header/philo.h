/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:57:45 by mraymond          #+#    #+#             */
/*   Updated: 2022/08/29 15:22:38 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>

enum e_error
{
	WRONG_NB_ARG,
	NOT_INT
};

typedef struct s_vars
{
	int	nb_philo;
	int	index_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
}				t_vars;

//0_main.c
int		error_message(int error);

//itoa.c
char	*ft_itoa(int n);

#endif