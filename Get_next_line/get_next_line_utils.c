/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:22:20 by danavarr          #+#    #+#             */
/*   Updated: 2024/08/17 16:35:37 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		j;
	char	*dest;

	len = (ft_strlen(s1));
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (dest == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		dest[j] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[len + j] = s2[j];
		j++;
	}
	dest[len + j] = '\0';
	free(s1);
	return (dest);
}
