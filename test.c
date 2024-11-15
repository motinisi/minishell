/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:21:10 by timanish          #+#    #+#             */
/*   Updated: 2024/11/15 19:33:53 by timanish         ###   ########.fr       */
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


// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	srclen;

// 	i = 0;
// 	srclen = 0;
// 	while (src[srclen] != '\0')
// 		srclen++;
// 	if (dstsize == 0)
// 		return (srclen);
// 	while (i < dstsize - 1 && src[i] != '\0')
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (srclen);
// }

// int main()
// {
//     char src[] = "Hello, World!";
//     char dst[20];  // コピー先のバッファ
//     size_t dstsize = 5;  // バッファサイズ
//     size_t copied_length;

//     copied_length = ft_strlcpy(dst, src, dstsize);

//     printf("コピー後のdst: \"%s\"\n", dst);
//     printf("コピーされた文字数（srcの長さ）: %zu\n", copied_length);

//     return 0;
// }


// #include "test.h"
// #include "libft.h"

// int main(int argc, char **argv)
// {
//     t_token *result;

//     if (1 < argc)
//     {
//         result = tokenization(argv[1]);
//         while (result)
//         {
//             printf("%s\n", result->data);
//             result = result->next;
//         }
//     }
// }