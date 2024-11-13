/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:21:10 by timanish          #+#    #+#             */
/*   Updated: 2024/11/05 14:10:31 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// int	main()
// {
//     char *input = readline("Enter something: ");

//     if (input == NULL) 
// 	{
//         printf("Input was interrupted.\n");
//     }
// 	else 
// 	{
//         printf("You entered: %s\n", input);
//         free(input); // メモリの解放
//     }

//     return 0;
// }


// int	main()
// {
// 	char	*input;

// 	while(1)
// 	{
// 		input = readline("c9r9s9% ");
// 		if (strlen(input))
// 			break;
// 	}
// 	printf("input : %s\n", input);
// 	free(input);

// 	return 0;
// }

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break ;
		if (*line)
			add_history(line);
		free(line);
	}
	return (0);
}
