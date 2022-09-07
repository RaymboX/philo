/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:57:45 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 12:12:41 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//LIBRARIES---------------------------------------------------------------------
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

//CONST-------------------------------------------------------------------------
# define MESSAGE_FORK " has taken a fork\n"
# define MESSAGE_EAT " is eating\n"
# define MESSAGE_SLEEP " is sleeping\n"
# define MESSAGE_THINK " is thinking\n"
# define MESSAGE_DIE " dead\n\n"

//ERROR MANAGEMENT--------------------------------------------------------------
# define ERR_NBARG "**Error** Wrong number of argument.\n\n"
# define ERR_ARG1 "**Error** Argument 1: number of philosopher -> "
# define ERR_ARG2 "**Error** Argument 2: time to die -> "
# define ERR_ARG3 "**Error** Argument 3: time to eat -> "
# define ERR_ARG4 "**Error** Argument 4: time to sleep -> "
# define ERR_ARG5 "**Error** Argument 5: how many time to eat -> "
# define ERR_NULL "Argument NULL\n\n"
# define ERR_TOBIG "Argument too big to be a integer\n\n"
# define ERR_NOTDIGIT "Argument contain non digit char\n\n"
# define ERR_NOTINT "Argument is not a integer\n\n"
# define ERR_UNDERMIN "Argument is under limit\n\n"
# define ERR_OVERMAX "Argument is over limit\n\n"
# define FORMAT "-------------------FORMAT TO USE----------------------------\n"
# define LIMITS "-------------------LIMITS TO USE----------------------------\n"

enum e_error
{
	WRONG_NB_ARG,
	ARG_NULL = 1,
	ARG_TOBIG = 2,
	ARG_NOTDIGIT = 3,
	ARG_NOTINT = 4,
	ARG_UNDERMIN = 5,
	ARG_OVERMAX = 6
};

//STRUCT------------------------------------------------------------------------
struct					s_vars;
typedef struct s_vars	t_vars;

typedef struct s_vars
{
	pthread_mutex_t		mutex_vars;
	int					nb_philo;
	int					die_duration;
	int					eat_duration;
	int					sleep_duration;
	int					nb_x_eat;
	long int unsigned	time_start;
	int					philo_dead;
	int					synchro_start;
}				t_vars;

typedef struct s_philo
{
	pthread_mutex_t		fork;
	pthread_mutex_t		*fork2;
	pthread_t			thread_philo;
	int					number;
	int					state;
	long int unsigned	last_eat;
	int					nb_x_eat;
	int					done;
	t_vars				*vars;
}				t_philo;

//PROTOTYPES--------------------------------------------------------------------
//0_main.c
void				create_philo_thread(t_vars *vars, t_philo **philo);
void				dead_n_eat_checker(t_vars *vars, t_philo **philo);
void				synchro_start_trigger(t_vars *vars);
void				synchro_start_relay(t_philo *philo);
int					dead_checker(t_vars *vars, t_philo **philo);
int					done_checker(t_vars *vars, t_philo **philo);

//1_parcing_err.c
int					arg_parcing(int argc, char **argv);
int					parcing_error_message(int error, int arg);
void				write_error_arg(int arg);
void				write_error_type(int error);

//2_vars_init_free.c
void				vars_init(t_vars *vars, int argc, char **argv);
t_philo				**philo_init(t_vars *vars);
void				free_n_destroy(t_philo **philo, t_vars *vars);

//3_philo_routine.c
void				*philo_routine(void *void_philo);
void				philo_delay(t_philo *philo);
void				state_message(t_vars *vars, int philo_num, char *message);

//4_philo_action.c
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_die(t_vars *vars, int philo_num);
void				philo_think(t_philo *philo);

//utils.c
int					ft_is_int_range(char *val, int min, int max);
int					ft_is_str_digit(char *str);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
int					ft_isspace(char c);

//itoa.c
char				*ft_itoa(int n);

//ft_atoi.c
int					ft_atoi(const char *nptr);

//ft_atol.c
long int			ft_atol(const char *nptr);

//ft_msleep.c
long unsigned int	now_millisecond(void);
void				ft_msleep(long unsigned int wait_millisecond);

//ft_free_dbl_ptr.c
void				free_dbl_ptr(void **ptr, int option);

//debug_fct.c
void				write_int(int i);

#endif