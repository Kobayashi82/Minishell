/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:44:59 by vzurera-          #+#    #+#             */
/*   Updated: 2024/05/08 12:40:55 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Check if input match a pattern. Support ? * and [] wildcards
static bool	match_pattern(t_wc *wc)
{
	while (wc->i < wc->input_len)
	{
		if (wc->j < wc->pattern_len && (wc->pattern[wc->j] == '?'
				|| (wc->pattern[wc->j] == '[' && brackets(wc))
				|| wc->pattern[wc->j] == wc->input[wc->i]))
		{
			wc->i++;
			wc->j++;
		}
		else if (wc->j < wc->pattern_len && wc->pattern[wc->j] == '*')
		{
			wc->match = wc->i;
			wc->start = wc->j++;
		}
		else if (wc->start != -1)
		{
			wc->j = wc->start + 1;
			wc->i = wc->match++;
		}
		else
			return (false);
	}
	while (wc->j < wc->pattern_len && wc->pattern[wc->j] == '*')
		wc->j++;
	return (wc->j == wc->pattern_len);
}

//	Initialize, delete duplicates of * wildcard and check if there is a match
static bool	optimize_pattern(char *input, char *pattern)
{
	t_wc	wc;

	ft_memset(&wc, 0, sizeof(t_wc));
	wc.input = input;
	wc.input_len = ft_strlen(input);
	wc.pattern_len = ft_strlen(pattern);
	wc.start = -1;
	while (pattern && pattern[wc.i])
	{
		if (pattern[wc.i] == '*' && pattern[wc.i + 1] == '*')
			ft_memmove(&pattern[wc.i], &pattern[wc.i + 1], \
				ft_strlen(&pattern[wc.i]));
		else
			wc.i++;
	}
	wc.pattern = pattern;
	wc.i = 0;
	return (match_pattern(&wc));
}

//	Add the matched input to a list of filenames
static void	files_add(t_data *data, char *filename, char *dir)
{
	t_args	*new_node;

	new_node = safe_malloc(data, sizeof(t_args));
	if (dir)
		new_node->arg = ft_strjoin_c(dir, filename, "/", 0);
	else
		new_node->arg = ft_strdup(filename);
	new_node->next = data->files;
	data->files = new_node;
}

//	Check if is a valid file or directory and add it to the list if matched
static int	files_get(t_data *data, struct dirent *de, char *pattern, char *dir)
{
	struct stat		stbuf;
	char			path[1024];

	ft_strncpy(path, dir, 1024);
	ft_strncat(path, "/", 1024);
	ft_strncat(path, de->d_name, 1024);
	if (stat(path, &stbuf) == -1)
		return (1);
	if ((S_ISREG(stbuf.st_mode) || S_ISDIR(stbuf.st_mode))
		&& optimize_pattern(de->d_name, pattern))
	{
		if (!data->extra)
			files_add(data, de->d_name, dir);
		else
			files_add(data, de->d_name, NULL);
	}
	return (0);
}

//	Open the directory and check every file and directory for a match
void	dir_get(t_data *data, char *cpattern, char *dir)
{
	DIR				*dr;
	struct dirent	*de;
	char			*pattern;

	pattern = ft_strdup(cpattern);
	dr = opendir(dir);
	if (dr && pattern)
	{
		de = readdir(dr);
		while (de)
		{
			if (((de->d_name[0] == '.' && *cpattern == '.')
					|| de->d_name[0] != '.')
				&& files_get(data, de, pattern, dir))
				break ;
			de = readdir(dr);
		}
	}
	if (dr)
		closedir(dr);
	free(pattern);
}
