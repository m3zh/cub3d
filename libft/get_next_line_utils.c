/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:44 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/09 07:37:15 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **line)
{
	if (line)
	{
		free(*line);
		*line = NULL;
	}
}

int	ft_return(char **keep, int ret)
{
	if (keep)
		ft_free(keep);
	return (ret);
}

char	*ft_join(char *s1, char *s2)
{
	char	*r;
	int		l;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (s2);
	l = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	while (*s1)
		r[i++] = *s1++;
	while (*s2)
		r[i++] = *s2++;
	r[i] = '\0';
	return (r);
}

static int	ft_lastline(char **keep, char **line, int fd)
{
	*line = ft_strdup(keep[fd]);
	if (!*line)
		return (ft_return(keep, -1));
	ft_free(&keep[fd]);
	return (0);
}

int	ft_fill_line(char **keep, char **line, int fd)
{
	char	*tmp;
	int		idx;

	idx = ft_strchr(keep[fd], '\n');
	if (idx != -1 && keep[fd][idx] == '\n')
	{
		*line = ft_substr(keep[fd], 0, idx);
		if (!*line)
			return (ft_return(keep, -1));
		tmp = ft_substr(keep[fd], idx + 1, ft_strlen(keep[fd]));
		if (!tmp)
			return (ft_return(keep, -1));
		ft_free(&keep[fd]);
		keep[fd] = ft_strdup(tmp);
		if (!keep[fd])
			return (ft_return(&tmp, -1));
		free(tmp);
	}
	else
		return (ft_lastline(keep, line, fd));
	return (1);
}
