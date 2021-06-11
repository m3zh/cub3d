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
