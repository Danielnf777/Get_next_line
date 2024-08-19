/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danavarr <danavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:55:00 by danavarr          #+#    #+#             */
/*   Updated: 2024/08/19 08:19:03 by danavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_txt(int fd, char *storage)
{
	int		i;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	i = 1;
	while (i > 0 && (!storage || (!ft_strchr(buffer, '\n'))))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		if (i > 0)
			storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (NULL);
	}
	free(buffer);
	return (storage);
}

char	*printline(char *storage)
{
	int			i;
	static int	j = 0;
	char		*theline;

	i = 0;
	if (!storage || storage[j] == '\0')
	{
		free(storage);
		return (NULL);
	}
	while (storage[j + i] != '\0' && storage[j + i] != '\n')
		i++;
	theline = (char *)malloc(sizeof(char) * (i + 2));
	if (!theline)
		return (NULL);
	i = 0;
	while (storage[j] != '\0' && storage[j] != '\n')
		theline[i++] = storage[j++];
	if (storage[j] == '\n')
		theline[i++] = storage[j++];
	theline[i] = '\0';
	return (theline);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!storage)
	{
		storage = (char *)malloc(sizeof(char) * 1);
		storage[0] = '\0';
	}
	if (storage == NULL)
		return (NULL);
	storage = read_txt(fd, storage);
	line = printline(storage);
	if (line == NULL)
	{
		return (NULL);
	}
	return (line);
}

/*int main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*result;
	if (fd < 0)
	{
		write(1, "Error opening file", 18);
		return (0);
	}
	while ((result = get_next_line(fd)) != NULL)
	{	
		printf("@@@@@@ %s\n",result);
		free(result);
	}
	close(fd);
	return (0);
}*/
