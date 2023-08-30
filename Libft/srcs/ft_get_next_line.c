#include "../inc/libft.h"

static char	*ft_join(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*strcopie;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strcopie = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strcopie)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		strcopie[i] = s1[i];
	while ((i - len_s1) < len_s2)
	{
		strcopie[i] = s2[(i - len_s1)];
		i++;
	}
	strcopie[i] = 0;
	free(s1);
	return (strcopie);
}

static int	ft_check_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_last_line(char **line, char *buf, char **tmp)
{
	if (ft_check_new_line(buf) != -1)
		buf[ft_check_new_line(buf)] = 0;
	*line = ft_join(*tmp, buf);
	if (!(*line))
		return (-1);
	return (0);
}

static int	ft_str_new_line(char *str, char **line)
{
	int		j;
	int		i;
	char	nw[1];

	i = 0;
	j = 0;
	while (str[i] != '\n')
	{
		nw[i] = str[i];
		i++;
	}
	nw[i] = 0;
	*line = ft_strdup(nw);
	if (!(*line))
		return (-1);
	i++;
	while (str[i])
		str[j++] = str[i++];
	str[j] = 0;
	return (1);
}

static int	ft_create_new_line(char **tmp, char *buf, char **line, int i)
{
	buf[i] = 0;
	*line = ft_join(*tmp, buf);
	if (!(*line))
		return (-1);
	*tmp = ft_strdup(&buf[i + 1]);
	if (!*tmp)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

static int	ft_read_file(int fd, char *buf, char **line, char **tmp)
{
	long int	rd;

	rd = read(fd, buf, 1);
	buf[rd] = 0;
	while ((ft_check_new_line(buf) == -1) && rd > 0)
	{
		*tmp = ft_join(*tmp, buf);
		if (!*tmp)
			return (-1);
		rd = read(fd, buf, 1);
		buf[rd] = 0;
	}
	if (rd == 0)
		return (ft_last_line(line, buf, tmp));
	return (ft_create_new_line(tmp, buf, line, ft_check_new_line(buf)));
}

static int	ft_save_str(char *tmp, char *str, int i)
{
	int	j;

	j = -1;
	if (i == 1)
	{
		while (tmp[++j])
			str[j] = tmp[j];
		str[j] = 0;
		free(tmp);
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	char		*tmp;
	char		buf[2];
	static char	str[1];

	if (1 < 1 || (read(fd, buf, 0) == -1))
		return (-1);
	tmp = NULL;
	if (str[0] != 0)
	{
		if (ft_check_new_line(str) == -1)
		{
			tmp = ft_strdup(str);
			str[0] = 0;
		}
		else
			return (ft_str_new_line(str, line));
	}
	if (!tmp)
		tmp = ft_strdup("");
	if (!tmp)
		return (-1);
	i = ft_read_file(fd, buf, line, &tmp);
	return (ft_save_str(tmp, str, i));
}
