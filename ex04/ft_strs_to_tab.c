#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*dest;

	length = ft_strlen(src);
	dest = (char *)malloc((length + 1) * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
	{
		return (NULL);
	}

	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (!array[i].copy)
		{
			while (i > 0)
			{
				i--;
				free(array[i].copy);
			}
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i].str = 0;

	return (array);
}
