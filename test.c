/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:37:48 by timanish          #+#    #+#             */
/*   Updated: 2024/12/03 17:54:27 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*quote_handling(char *str)
{
	size_t	i;
	char	quote;

	if (str[0] == '"')
		quote = '"';
	else
		quote = '\'';
	str++;
	i = 0;
	while (*str)
	{
		if (*str == quote)
		{
			str ++;
			return (str);
		}
		str ++;
	}
	return (str);
}

size_t	quote_handling_word(const char *str, size_t cnt)
{
	char	quote;

	if (str[cnt] == '"')
		quote = '"';
	else if (str[cnt] == '\'')
		quote = '\'';
	else
		return (++cnt);
	cnt++;
	while (str[cnt])
	{
		if (str[cnt] == quote)
		{
			cnt ++;
			return (cnt);
		}
		cnt++;
	}
	return (cnt);
}

int	main(void)
{
	char	*re;
	size_t	cnt;

	re = "\" \"";
	cnt = 0;
	if (re[0] != '"' && re[0] != '\'')
	{
		printf("no quote\n");
		return (0);
	}
	cnt = quote_handling_word(re, cnt);
	printf("cnt : %zu\n", cnt);
	// re = quote_handling(re);
	// printf("result : %s\n", re);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	char	*re;

// 	if (argc < 2)
// 	{
// 		printf("no arg\n");
// 		return (0);
// 	}
// 	if (argv[1][0] != '"' && argv[1][0] != '\'')
// 	{
// 		printf("no quote\n");
// 		return (0);
// 	}
// 	re = quote_handling(argv[1]);
// 	printf("result : %s\n", re);
// 	return (0);
// }

