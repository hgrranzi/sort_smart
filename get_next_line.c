/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uteena <uteena@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:32:17 by uteena            #+#    #+#             */
/*   Updated: 2020/11/30 10:18:20 by uteena           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	make_draft(char **draft_line, char **buffer)
{
	char	*draft_ptr;

	if (!*draft_line)
		draft_ptr = ft_strdup(*buffer);
	else
	{
		draft_ptr = ft_strjoin(*draft_line, *buffer);
		free(*draft_line);
	}
	*draft_line = draft_ptr;
}

static int	make_line(char **line, char **draft_line, char **buffer)
{
	char	*cut_point;
	char	*draft_ptr;

	cut_point = ft_strchr(*draft_line, '\n');
	*cut_point = '\0';
	cut_point++;
	*line = ft_strdup(*draft_line);
	if (*line == NULL)
		return (-1);
	if (*cut_point == '\0')
	{
		free(*draft_line);
		*draft_line = NULL;
	}
	else
	{
		draft_ptr = ft_strdup(cut_point);
		free(*draft_line);
		*draft_line = draft_ptr;
	}
	free(*buffer);
	buffer = NULL;
	return (1);
}

static int	gnl_end(char **line, char **draft_line)
{
	if (!*draft_line)
		return (0);
	*line = ft_strdup(*draft_line);
	if (*line == NULL)
		return (-1);
	free(*draft_line);
	*draft_line = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*draft_line;
	int			read_return;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((read_return = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		buffer[read_return] = '\0';
		make_draft(&draft_line, &buffer);
		if (ft_strchr(draft_line, '\n'))
			return (make_line(line, &draft_line, &buffer));
		if (read_return < BUFFER_SIZE)
		{
			free(buffer);
			buffer = NULL;
			return (gnl_end(line, &draft_line));
		}
	}
	*line = NULL;
	return (-1);
}
