/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:28:30 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/20 17:48:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env				**get_head_env(void);
t_env				*get_env(char *key);
char				*get_env_value(char *key);
void				set_env_value(char *key, char *value);

t_env				*create_env(char *key, char *value);
void				init_env(char *envp[]);

void				remove_all_env(void);
void				remove_env(char *key);

char				**get_env_to_array(void);
