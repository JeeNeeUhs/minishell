/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 14:37:45 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 1
# define FAILURE 0

#include <stddef.h>

int		is_quote(char c);
int		is_operator(char c);
int		is_metacharacter(char c);
int		is_blank(char c);
int		is_word_char(char c);

int		find_char_index(char *str, int start_index, char c);
int		skip_whitespace(char *str);
int		str_equal(char *s1, char *s2);

char	*ft_pstrdup(const char *s);
char	*ft_psubstr(char const *s, unsigned int start, size_t len);

int		safe_exit(int status, char *message);

#endif
