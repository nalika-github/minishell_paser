/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:50:46 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/28 20:55:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	error_exit(t_minishell *ms, char *line)
{
	t_list	*tk_lst;

	free(line);
	tk_lst = ms->tk_lst;
	printf("error\n");
	ft_lstclear(&tk_lst, &free);
	return (1);
}

static int special_char_validate(t_minishell *ms)
{
	t_list	*tk_lst;
	t_token	*token;

	tk_lst = ms->tk_lst;
	tk_lst = ft_lstlast(tk_lst);
	token = ((t_token *)(tk_lst->data));
	if(token->type == HEREDOC || token->type == INFILE || \
	token->type == APPEND || token->type == OUTFILE || token->type == PIPE)
		return (1);
	return (0);
}

int	lexer(char *line, t_minishell *ms)
{
	if (init_command_list(&ms, line))
		return (error_exit(ms, line));
	if (quotes_validate(ms))
		return (error_exit(ms, line));
	if (tokenize(&ms))
		return (error_exit(ms, line));
	if (special_char_validate(ms))
		return (error_exit(ms, line));
	free(line);
	return (0);
}


