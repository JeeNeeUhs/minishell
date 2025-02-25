/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 11:14:06 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define SUCCESS 1
#define FAILURE 0

int	is_quote(char c);
int	is_operator(char c);
int	is_metacharacter(char c);
int is_blank(char c);
int find_char_index(char *str, int start_index, char c);
int skip_whitespace(char *str);
int	str_equal(char *s1, char *s2);

int safe_exit(int status, char *message);

#endif
