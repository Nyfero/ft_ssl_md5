#include "../inc/libft.h"

char	*ft_strappend(char const *s1, char const *s2) {
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = ft_strlen(s1) + ft_strlen(s2);
	char	*strcopie;

	if (!s1 || !s2)
		return (NULL);
	strcopie = (char *)malloc(sizeof(char) * (k + 1));
	if (!strcopie)
		return (NULL);
	while (i < k) {
		if (i < ft_strlen(s1))
			strcopie[i] = s1[i];
		else {
			strcopie[i] = s2[j];
			j++;
		}
		i++;
	}
	strcopie[i] = '\0';
    free((char *)s1);
	return (strcopie);
}