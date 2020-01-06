/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:42:32 by amalsago          #+#    #+#             */
/*   Updated: 2020/01/06 14:40:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	display_prompt() display a personalized prompt if USER variable is setted,
**	otherwise a simple prompt.
**
** RETURN VALUES
**	This function do not return a value.
*/

void			display_prompt(void)
{
	const char	*user = NULL;

	if (user == NULL)
		user = ft_getenv("USER");
	ft_printf(SGR_BFG_RED);
	if (user)
		ft_printf("%s$> ", user);
	else
		ft_printf("$> ");
	ft_printf(SGR_NORMAL);
}
