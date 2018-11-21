#include "../../ft_printf.h"

char	*fstrjoin(char *s1, char *s2)
{
	char	*ptr;
	
	ptr = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (ptr);
}