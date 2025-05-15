/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:27:32 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 16:29:25 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inbuild.h"
#include "minishell.h"
#include "libft.h"
#include "env.h"
#include "token.h"
#include "memory_allocator.h"
void	test_str_arr_join();
void	test_str_sep();

#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	execve(NULL, NULL, NULL);

	return (0);
}

__attribute__((constructor))
void	run_tests()
{
	test_str_arr_join();
	test_str_sep();
}


__attribute__((destructor))
void	end_tests()
{
	safe_abort(STD_EXIT);
}

void	test_str_arr_join()
{
	char	*test_cases[] = {
		str_arr_join(NULL, 0),
		str_arr_join((char *[]){0}, 0),
		str_arr_join((char *[]){"hello"}, 1),
		str_arr_join((char *[]){"", ""}, 2),
		str_arr_join((char *[]){NULL, "world", ""}, 3),
		str_arr_join((char *[]){"hello", "world"}, 2),
		str_arr_join((char *[]){NULL, "world", "hello", ""}, 4),
		str_arr_join((char *[]){"this", "is", "a", "very", "long", "test", "string", "for", "joining"}, 9),
		str_arr_join((char *[]){NULL, NULL, NULL}, 3),
		str_arr_join((char *[]){" ", "  ", "   "}, 3),
		str_arr_join((char *[]){"hello!", "how", "are", "you?", "$USER", "100%"}, 6
		),
		str_arr_join((char *[]){NULL, "hello", " ", NULL, "world", "!"}, 6),
		str_arr_join((char *[]){"", "hello", "", "world", ""}, 5),

	};

	char	*expected_results[] = {
		"",
		"",
		"hello",
		"",
		"world",
		"helloworld",
		"worldhello",
		"thisisaverylongteststringforjoining",
		"",
		"   ",
		"hello!howareyou?$USER100%",
		"hello world!",
		"helloworld",
	};

	for (int i = 0; i < sizeof(test_cases) / sizeof(char *); i++)
	{
		if (ft_strncmp(test_cases[i], expected_results[i], ft_strlen(expected_results[i])) != 0 )
		{
			printf("❌ Test %d failed!\n", i + 1);
			printf("	Expected: \"%s\"\n", expected_results[i]);
			printf("	Got     : \"%s\"\n", test_cases[i]);
			return ;
		}
		else
			printf("✅ Test %d passed\n", i + 1);
	}
	printf("✅ All tests completed.\n\n");
}



