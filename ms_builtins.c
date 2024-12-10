/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:31:18 by timanish          #+#    #+#             */
/*   Updated: 2024/12/10 18:34:59 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_builtins.h>

size_t	cmd_len(t_cmd *cmd)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (((char **)cmd->cmd_argv->data)[i])
	{
		len ++;
		i ++;
	}
	return (len);
}

char	**conversion_to_str(t_cmd	*cmd)
{
	size_t		len;
	size_t		i;
	char		**com;

	len = cmd_len(cmd);
	com = (char **)malloc(sizeof(char *) * (len + 1));
	// printf("cmd_argv len : %zu\n", len);
	i = 0;
	while (((char **)cmd->cmd_argv->data)[i])
	{
		com[i] = ft_strdup(((char **)cmd->cmd_argv->data)[i]);
		i ++;
	}
	com[i] = NULL;
	return (com);
}

void	all_free(char **com)
{
	size_t	i;

	i = 0;
	while (com[i])
	{
		free(com[i]);
		i ++;
	}
	free(com);
}

// void	builtin_cmd(void)
void	builtin_cmd(t_cmd *cmd, char **envp)
{
	// static char	*test_cmd[] = {"echo", "hello", "42tokyo", NULL};
	char		**com;
	size_t		i;

	ft_printf("---------- builtins_test ----------\n\n");

	while (cmd)
	{
		i = 0;
		com = conversion_to_str(cmd);
		if (!ft_strcmp(com[0], "echo"))
			builtin_echo(com);
		else if (!ft_strcmp(com[0], "pwd"))
			builtin_pwd(com);
		cmd = cmd->next;
		all_free(com);
	}
	printf("\n\n");
}

// int	builtin_echo(t_cmd *cmd)
int	builtin_echo(char **cmd)
{
	int			newline_flag;
	size_t		i;
	size_t		j;

	newline_flag = 1;
	i = 1;
	if (cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0)
	{
		newline_flag = 0;
		i ++;
	}
	while (cmd[i])
	{
		j = 0;
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i ++;
	}
	if (newline_flag)
		printf("\n");
	return (0);
}

int	builtin_pwd(char **cmd)
{
	char	*cwd;

	if (cmd[1])
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

int	builtin_export(char **cmd, char ***envp)
{
	char	**envp;

	envp = 
}
