/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:10:52 by amalsago          #+#    #+#             */
/*   Updated: 2019/11/04 18:37:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	builtin_echo(const char *line);
void	builtin_env(void);
void	builtin_exit(void);
void	builtin_setenv(const char *line);

static char *g_builtins[] = {
	"cd",
	"echo",
	"env",
	"exit",
	"setenv",
	"unsetenv",
};

#endif
