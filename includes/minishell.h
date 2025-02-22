/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 13:13:24 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define SUCCESS 1
#define FAILURE 0

int skip_whitespace(char *str);
int	is_quote(char c);
int	is_operator(char c);
int	is_metacharacter(char c);
int is_blank(char c);

int safe_exit(int status, char *message);

int find_char_index(char str, int start_index, char c);
#endif
