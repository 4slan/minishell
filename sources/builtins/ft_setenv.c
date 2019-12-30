/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:44:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/30 02:51:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** DESCRIPTION
**	ft_setenv()
**
** RETURN VALUES
**	ft_setenv()
**		Upon successful completion, the value 1 is returned otherwise 0.
*/

extern char		**environ;

static int		is_exceptions(const char *name)
{
	int			i;

	i = -1;
	if (!ft_isalpha(name[0]))
	{
		ft_perror("setenv: Variable name must begin with a letter.");
		return (1);
	}
	while (name[++i])
		if (!ft_isalnum(name[i]))
		{
			ft_perror("setenv: Variable name must contain alphanumeric characters.");
			return (1);
		}
	return (0);
}

static void		write_environ_variable(const char *new_variable)
{
	int			i;
	char		**tmp;
	char		**new_environ;

	i = -1;
	if (!environ || !*environ)
	{
		if (!(new_environ = ft_strnew2d(1))) // MALLOC
			ft_perror_exit("ft_strnew2d() failed in ft_setenv()");
		new_environ[0] = (char *)new_variable;
		new_environ[1] = NULL;
	}
	else
	{
		tmp = environ;
		if (!(new_environ = ft_strnew2d(total_environ_rows() + 1))) // MALLOC
			ft_perror_exit("ft_strnew2d() failed in ft_setenv()");
		while (environ[++i])
			new_environ[i] = environ[i];
		new_environ[i] = (char *)new_variable;
		new_environ[i + 1] = NULL;
		free(tmp);
	}
	environ = new_environ;
}

static void		overwrite_environ_variable(const char *name,
				const char *new_variable)
{
	int			i;
	int			len;

	i = -1;
	while (environ[++i])
	{
		len = ft_strlen(name);
		if (ft_strnequ(environ[i], name, len) && environ[i][len] == '=')
		{
			ft_strdel(&environ[i]);
			environ[i] = (char *)new_variable;
			break ;
		}
	}
}

static char		*set_new_variable(const char *name, const char *value)
{
	char		*new_variable;

	new_variable = ft_strnew(((value) ? ft_strlen(value) : 0) // MALLOC
							+ ft_strlen(name) + 1);
	ft_strcpy(new_variable, name);
	ft_strcat(new_variable, "=");
	ft_strcat(new_variable, (value) ? value : "");
	return (new_variable);
}

int				ft_setenv(const char *name, const char *value, int overwrite)
{
	char		*new_variable;

	if (is_exceptions(name))
		return (0);
	new_variable = set_new_variable(name, value); //MALLOC
	if (!is_var_exist(name))
		write_environ_variable(new_variable);
	else
		if (overwrite == 1)
			overwrite_environ_variable(name, new_variable);
	return (1);
}
