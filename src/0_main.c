/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:00:16 by mraymond          #+#    #+#             */
/*   Updated: 2022/08/30 11:37:51 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (arg_parcing(argc, argv) != 0)
		return (1);
	record_arg_val_in_vars(&vars, argc, argv);
	return (0);
}

void	record_arg_val_in_vars(t_vars *vars, int argc, char **argv)
{
	vars->nb_philo = ft_atoi(argv[1]);
	vars->time_die = ft_atoi(argv[2]);
	vars->time_eat = ft_atoi(argv[3]);
	vars->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->nb_x_eat = ft_atoi(argv[5]);
	else
		vars->nb_x_eat = -1;
}

int	arg_parcing(int argc, char **argv)
{
	int	arg_num;
	int	fct_ret;

	if (argc < 5 || argc > 6)
		return (parcing_error_message(WRONG_NB_ARG, 0));
	fct_ret = ft_is_int_range(argv[1], 1, 200);
	if (fct_ret != 0)
		return (parcing_error_message(fct_ret, 1));
	arg_num = 2;
	while (arg_num < argc && fct_ret == 0)
	{
		fct_ret = ft_is_int_range(argv[arg_num], 0, INT_MAX);
		arg_num++;
	}
	if (fct_ret != 0)
		return (parcing_error_message(fct_ret, --arg_num));
	return (0);
}

int	parcing_error_message(int error, int arg)
{
	if (error == WRONG_NB_ARG)
		write(2, ERR_NBARG, ft_strlen(ERR_NBARG));
	else
	{
		write_error_arg(arg);
		write_error_type(error);
	}
	write(2, FORMAT, ft_strlen(FORMAT));
	write(2, "./philo  <nb_philo>  <time_to_die>  <time_to_eat>"
		"  <time_to_sleep>  <optional:how_many_time_to_eat>\n\n", 101);
	write(2, LIMITS, ft_strlen(LIMITS));
	write(2, "./philo  <1_to_200>  <0_to_INTMAX>  <0_to_INTMAX>  <0_to_INTMAX>"
		"  <Nothing_or_0_to_INTMAX>\n\n", 93);
	return (1);
}

void	write_error_arg(int arg)
{
	if (arg == 1)
		write(2, ERR_ARG1, ft_strlen(ERR_ARG1));
	if (arg == 2)
		write(2, ERR_ARG2, ft_strlen(ERR_ARG2));
	if (arg == 3)
		write(2, ERR_ARG3, ft_strlen(ERR_ARG3));
	if (arg == 4)
		write(2, ERR_ARG4, ft_strlen(ERR_ARG4));
	if (arg == 5)
		write(2, ERR_ARG5, ft_strlen(ERR_ARG5));
}

void	write_error_type(int error)
{
	if (error == ARG_NULL)
		write(2, ERR_NULL, ft_strlen(ERR_NULL));
	if (error == ARG_TOBIG)
		write(2, ERR_TOBIG, ft_strlen(ERR_TOBIG));
	if (error == ARG_NOTDIGIT)
		write(2, ERR_NOTDIGIT, ft_strlen(ERR_NOTDIGIT));
	if (error == ARG_NOTINT)
		write(2, ERR_NOTINT, ft_strlen(ERR_NOTINT));
	if (error == ARG_UNDERMIN)
		write(2, ERR_UNDERMIN, ft_strlen(ERR_UNDERMIN));
	if (error == ARG_OVERMAX)
		write(2, ERR_OVERMAX, ft_strlen(ERR_OVERMAX));
}

/*return 0: GOOD -> val is a int and in range 
Error list: 1:val null 2:nb_char > max/min int 3:not only digit 
4:over or lower than a int 5:under range min 6=over range max*/
int	ft_is_int_range(char *val, int min, int max)
{
	char	*char_int_min;

	if (val == NULL || ft_strlen(val) < 1)
		return (1);
	char_int_min = ft_itoa(INT_MIN);
	if (ft_strlen(val) >= ft_strlen(char_int_min))
		return (2);
	if (val[0] == '-' && ft_strlen(val) == 1)
		return (3);
	if (val[0] == '-' && ft_is_str_digit(val + 1) != 0)
		return (3);
	if (val[0] != '-' && ft_is_str_digit(val) != 0)
		return (3);
	if (ft_atoi(val) != ft_atol(val))
		return (4);
	if (ft_atoi(val) < min)
		return (5);
	if (ft_atoi(val) > max)
		return (6);
	return (0);
}

//return 0 if str contain only digit
int	ft_is_str_digit(char *str)
{
	int	i;

	if (str == NULL)
		return (1);
	i = 0;
	while (str[i] && ft_isdigit((int)str[i]) == 1)
		i++;
	if (str[i] != '\0')
		return (2);
	return (0);
}

//Return 1 if c is number else 0
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}

//return 1 if space
int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}