/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 10:31:16 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 13:00:42 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trimspaces(char *s)
{
	int		i;
	int		k;
	int		len;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	len = (int)ft_strlen(s) - 1;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (len > i && s[len] && ft_isspace(s[len]))
		len--;
	r = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!r)
		return (NULL);
	while (i <= len)
		r[k++] = s[i++];
	r[k] = '\0';
	return (r);
}

int	ft_isplayerpos(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	ft_ismaze(char c)
{
	return (c == '0' || c == '2');
}

int	ft_isdirection(char *li, int i)
{
	return (((li[i] == 'N' || li[i] == 'S') && li[i + 1] == 'O')
		|| (li[i] == 'W' && li[i + 1] == 'E')
		|| (li[i] == 'E' && li[i + 1] == 'A'));
}

int	ft_issprite(char a, char b)
{
	return (a == 'S' && ft_isspace(b));
}
