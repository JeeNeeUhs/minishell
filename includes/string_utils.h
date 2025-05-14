/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:36:53 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 14:44:12 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

int		find_char_index(char *str, int start_index, char c);
int		skip_whitespace(char *str);
int		str_equal(char *s1, char *s2);
int		includes(char *str, char c);

char	*ft_pstrdup(const char *s);
char	*ft_psubstr(char const *s, unsigned int start, size_t len);

char	*str_arr_join(char	**strings, int count);
void	str_arr_free(char **strings, int count);

#endif
