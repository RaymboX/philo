/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:30 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/01 15:27:31 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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
