/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:02:14 by mraymond          #+#    #+#             */
/*   Updated: 2022/08/30 13:02:30 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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
