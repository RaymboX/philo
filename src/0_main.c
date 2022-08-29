/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:00:16 by mraymond          #+#    #+#             */
/*   Updated: 2022/08/29 15:23:48 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fct_ret;

	fct_ret = arg_parcing(&vars, argc, argv);
	if (fct_ret != 0)
		return (error_message(fct_ret));

	return (0);
}

int	arg_parcing(t_vars *vars, int argc, char **argv)
{
	int	arg_num;

	if (argc < 5 || argc > 6)
		return (error_message(WRONG_NB_ARG));
	if (is_int_range(argc[1], 1))
	arg_num = 1
	while (++arg_num < argc && is_int_range(argv[arg_num], ))
	return (0);
}

int	error_message(int error)
{
	if (error == WRONG_NB_ARG)
		printf("Wrong number of argument. Use the format below\n"
			"./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep>"
			" <optional:how_many_time_to_eat>\n./philo <1 to 200> <0 to INTMAX>"
			" <0 to INTMAX> < 0 to INTMAX > <   nothing or 0 to INTMAX    >");
	return (error);
}

//return 0 if good
int	ft_is_int_range(char *val, int min, int max)
{
	char	*char_int_max;

	char_int_max = ft_itoa(INT_MAX);

	if (ft_strlen(val) >= ft_strlen(char_int_max))
		return (1);
	if (ft_is_str_digit(val) != 0)
		return (2);
	if ()
	
}

//return 0 if str contain only digit
int	ft_is_str_digit(char *str)
{
	int	c;
	int	i;

	if (str == NULL)
		return (1);
	i = 0;
	while (str[i] && ft_isdigit((int)str[i]) == 1)
		i++;
	if (!(str[i]))
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