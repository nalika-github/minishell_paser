/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:52:18 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/29 00:39:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	slide_n_decide(t_list *tk_lst, char *line)
{
	while (*line)
	{
		if (tk_lst == NULL)
		{
			if (ft_isquote(*line))
				return (2);
			if (ft_ismetachar(*line))
				return (3);
			return (0);
		}
		else if (ft_isquote(*line))
			return (2);
		else if (ft_ismetachar(*line))
			return (3);
		else if (!ft_isspace(*line))
			return (1);
		line++;
	}
	return (-1);
}

// void	print_lst(t_list *tk_lst)
// {
// 	while(tk_lst)
// 	{
// 		printf("token->str = %s\n", ((t_token*)tk_lst->data)->str);
// 		tk_lst = tk_lst->next;
// 	}
// }

int	init_command_list(t_minishell **ms, char *line)
{
	t_list	*tk_lst;
	char	*ptr_line;
	int		index;

	ptr_line = line;
	tk_lst = NULL;
	while (*ptr_line)
	{
		index = slide_n_decide(tk_lst, ptr_line);
		if (index == -1)
			return (1);
		grab_to_lst(&tk_lst, &ptr_line, index);
	}
	// print_lst(tk_lst);
	(*ms)->tk_lst = tk_lst;
	return (0);
}
