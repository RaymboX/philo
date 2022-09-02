# include "../header/philo.h"

void	write_int(int i)
{
	char	*i_str;

	i_str = ft_itoa(i);
	write(1, i_str, ft_strlen(i_str));
	free(i_str);
}
