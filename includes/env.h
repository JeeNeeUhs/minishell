/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:28:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 10:38:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*get_root_env(void);
t_env	*create_env(char *key, char *value);

void	remove_all_env();
void	remove_env(char *key);

