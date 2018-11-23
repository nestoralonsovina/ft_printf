/*#include "ft_printf.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(*to_find))
		return ((char *)(&str[i]));
	while (str[i])
	{
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)(&str[i]));
		j = 0;
		i += 1;
	}
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;

	c = (unsigned char)c;
	ch = (unsigned char *)b;
	while (len--)
		*ch++ = c;
	return (b);
}

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc(size + 1);
	if (!s)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}*/