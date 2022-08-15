
#include "so_long.h"

void    walkwrite(t_data *data)
{
	char	*variable;

	variable = ft_itoa(data->walk);
    if (data->walkcheck == 0) 
        ft_printf("walk %d\n", data->walk);
	mlx_string_put(data->mlx, data->mlx_window, 10, 20, 0x00FF00, "Step : ");
	mlx_string_put(data->mlx, data->mlx_window, 55, 20, 0x00FF00, variable);
	free(variable);
}

int	itoacount(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
	{
		l++;
	}
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		k;
	char	*last;

	k = itoacount(n);
	last = (char *)malloc(k * sizeof(char) + 1);
	if (!last)
		return (0);
	if (n == 0)
		*last = '0';
	while (n)
	{
		*(last + --k) = (n % 10) + 48;
		n /= 10;
	}
	return (last);
}