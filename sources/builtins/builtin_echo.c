/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:41 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/06 11:13:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		builtin_echo(const char *line)
{
	char	*args;
	char	*token;
	int		last_char;

	args = ft_strtrim(line + 4);
	if (args[0] == '"')
	{
		last_char = ft_strlen(args);
		if (args[last_char - 1] == '"')
			args[last_char - 1] = '\0';
		ft_printf("%s\n", args + 1);
	}
	else
	{
		token = ft_strtok(args, " \t");
		while (token)
		{
			ft_printf("%s", token);
			token = ft_strtok(NULL, " \t");
			ft_putchar((token) ? ' ' : '\n');
		}
	}
	ft_strdel(&args);
	exit(EXIT_SUCCESS);
}
