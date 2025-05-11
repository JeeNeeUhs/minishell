/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 15:57:53 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#ifndef DEBUG
# define DEBUG 0
#endif

# define SUCCESS 1
# define FAILURE 0

# define SHELL_NAME "hash"

# define DEFAULT_IFS " \t\n"

# define PPROMPT "\033[31m\\u@\033[0m\033[34m~\\w:\\s\033[0m$ "
# define SPROMPT "> "
# define ESC_CHR "shawu"

# include <stddef.h>

int		is_quote(char c);
int		is_operator(char c);
int		is_metacharacter(char c);
int		is_blank(char c);
int		is_word_char(char c);
int		is_var_char(char c);
int		is_var_start(char *input);

int		find_char_index(char *str, int start_index, char c);
int		skip_whitespace(char *str);
int		str_equal(char *s1, char *s2);
int		includes(char* str, char c);
char	*str_arr_join(char	**strings, int count);
void	str_arr_free(char **strings, int count);
char	**split_by_delims(char *str, char *delim);
int		replace_with_expansion(char **input, int index, char *rep, int offset);


char	*ft_pstrdup(const char *s);
char	*ft_psubstr(char const *s, unsigned int start, size_t len);

int		safe_exit(int status, char *message);
void	*report_syntax_error(char* message);
int		*get_exit_status(void);

//Prompt
char	*expand_prompt_string(char *input);

#endif
