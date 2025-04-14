/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:02:43 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/14 18:08:59 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"
#include "env.h"
#include "libft.h"

/*
2.6.5 Field Splitting {
	=> https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_06_05
	=> default IFS value: {
		<space>,
		<tab>,
		<newline>
	}
}
*/
char	*get_ifs(void)
{
	char	*ifs;

	ifs = get_env_value("IFS");
	if (!ifs)
		ifs = ft_strdup(DEFAULT_IFS);
	return (ifs);
}

int	letter_count(char *s, char *delim)
{
	int	i;

	i = 0;
	while (s[i] && !includes(delim, s[i]))
		i++;
	return (i);
}

static void	word_state(char *str, int *i, char *delims, t_token **head_token)
{
	t_token	*token;
	int		slen;

	slen = letter_count(str + *i, delims);
	token = create_token((t_token){.content = ft_substr(str + *i, 0, slen), .type = W_SINGLE_Q});
	append_token(head_token, token);
	*i += slen;
}

static void	delimiter_state(char *str, int *i, char *delims, t_token **head_token)
{
	while (includes(delims, str[*i]))
		(*i)++;
	append_token(head_token, create_token((t_token){.type = DELIM}));
}

static t_ifs_state	get_ifs_state(char c, char *delims)
{
	if (includes(delims, c))
		return (delimiter_state);
	return (word_state);
}

t_token	*field_split(char *str, char *delims)
{
	t_token	*tokens;
	int		i;

	i = 0;
	tokens = NULL;
	while (str[i])
		get_ifs_state(str[i], delims)(str, &i, delims, &tokens);
	return (tokens);
}
