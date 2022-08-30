/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:57:45 by mraymond          #+#    #+#             */
/*   Updated: 2022/08/30 13:20:56 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

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
//-----------------------------------------------------------------------------

typedef struct s_vars
{
	int	nb_philo;
	int	index_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_x_eat;
	int	**fork;
}				t_vars;

typedef struct s_philo
{
	int	index;
	
}				t_philo;

//0_main.c
int			parcing_error_message(int error, int arg);
void		record_arg_val_in_vars(t_vars *vars, int argc, char **argv);
int			arg_parcing(int argc, char **argv);
void		write_error_arg(int arg);
void		write_error_type(int error);
int			ft_is_int_range(char *val, int min, int max);
int			ft_is_str_digit(char *str);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
int			ft_isspace(char c);

//itoa.c
char		*ft_itoa(int n);

//ft_atoi.c
int			ft_atoi(const char *nptr);

//ft_atol.c
long int	ft_atol(const char *nptr);

#endif