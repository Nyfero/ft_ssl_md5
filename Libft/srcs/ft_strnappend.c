#include "../inc/libft.h"

char	*ft_strnappend(char const *s1, char const s2, int n) {
	size_t	i = 0;
    size_t  len = ft_strlen(s1);
    size_t	k = len + n;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (k + 1));
	if (!str)
		return (NULL);
	while (i < k) {
		if (i < len)
			str[i] = s1[i];
        else 
			str[i] = s2;
		i++;
	}
	str[i] = '\0';
    free((char *)s1);
	return (str);
}