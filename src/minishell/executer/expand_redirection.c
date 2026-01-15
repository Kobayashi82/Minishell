/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:15:44 by vzurera-          #+#    #+#             */
/*   Updated: 2026/01/15 00:58:43 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/mman.h>

//	Close and free some data from expand_input()
int	expand_closer(int fd, char *text)
{
	if (fd != -1)
		close(fd);
	if (text)
		free(text);
	return (0);
}

//	Open, expand a redirection input and write the result
int	expand_input(t_data *data, t_redir *redir)
{
	int			fd;
	int			readed;
	char		*text;
	struct stat	st;

	if (!redir->expand)
		return (0);
	text = NULL;
	fd = open(redir->file, O_RDONLY | O_CLOEXEC);
	if (fd == -1 || fstat(fd, &st) == -1)
		return (expand_closer(fd, text));
	text = malloc(st.st_size + 1);
	data->tmp_heredoc = text;
	if (text == NULL)
		return (expand_closer(fd, text));
	readed = read(fd, text, st.st_size);
	if (readed == -1)
		return (expand_closer(fd, text));
	text[readed] = '\0';
	close(fd);
	expand_heredoc(data, &text);
	fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0600);
	if (fd != -1 && text)
		write(fd, text, ft_strlen(text));
	return (data->tmp_heredoc = NULL, expand_closer(fd, text));
}
