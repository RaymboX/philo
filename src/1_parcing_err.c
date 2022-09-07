/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parcing_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:26:44 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/07 14:57:04 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

//Check the number of args & if is int and in range
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
		fct_ret = ft_is_int_range(argv[arg_num], 1, INT_MAX);
		arg_num++;
	}
	if (fct_ret != 0)
		return (parcing_error_message(fct_ret, --arg_num));
	return (0);
}

//Print error_message of first problem saw
int	parcing_error_message(int error, int arg)
{
	printf("%s\n", KRED);
	if (error == WRONG_NB_ARG)
		printf("%s", ERR_NBARG);
	else
	{
		print_error_arg(arg);
		print_error_type(error);
	}
	printf("%s\n", KCYN);
	printf("%s", FORMAT);
	printf("./philo  <nb_philo>  <time_to_die>  <time_to_eat>"
		"  <time_to_sleep>  <optional:how_many_time_to_eat>\n\n");
	printf("%s", KYEL);
	printf("%s", LIMITS);
	printf("./philo  <1_to_200>  <1_to_INTMAX>  <1_to_INTMAX>  <1_to_INTMAX>"
		"  <Nothing_or_1_to_INTMAX>\n\n");
	printf("%s", KNRM);
	return (1);
}

//Print the number and name of the first argument with error
void	print_error_arg(int arg)
{
	if (arg == 1)
		printf("%s", ERR_ARG1);
	if (arg == 2)
		printf("%s", ERR_ARG2);
	if (arg == 3)
		printf("%s", ERR_ARG3);
	if (arg == 4)
		printf("%s", ERR_ARG4);
	if (arg == 5)
		printf("%s", ERR_ARG5);
}

//Print the type of error
void	print_error_type(int error)
{
	if (error == ARG_NULL)
		printf("%s", ERR_NULL);
	if (error == ARG_TOBIG)
		printf("%s", ERR_TOBIG);
	if (error == ARG_NOTDIGIT)
		printf("%s", ERR_NOTDIGIT);
	if (error == ARG_NOTINT)
		printf("%s", ERR_NOTINT);
	if (error == ARG_UNDERMIN)
		printf("%s", ERR_UNDERMIN);
	if (error == ARG_OVERMAX)
		printf("%s", ERR_OVERMAX);
}
