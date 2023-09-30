/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_n_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:15:57 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/30 18:51:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(char **ep_str, t_dict *dict)
{
	char	*ep_str_ptr;

	ep_str_ptr = *ep_str;
	ep_str_ptr++;
	while(dict)
	{
		if (ft_strncmp(ep_str_ptr, dict->tmp_dict->key, ft_strlen(ep_str_ptr)) == 0 && \
		ft_strncmp(dict->tmp_dict->key, ep_str_ptr, ft_strlen(dict->tmp_dict->key)) == 0)
		{
			free(*ep_str);
			*ep_str = ft_strdup(dict->tmp_dict->value);
			return ;
		}
		dict = dict->next;
	}
	free(*ep_str);
	*ep_str = ft_strdup("");
}

void	scan_n_expand(t_list **ep_lst, t_dict *dict)
{
	char	*ep_str;
	t_list	*ep_lst_ptr;

	ep_lst_ptr = *ep_lst;
	while(ep_lst_ptr)
	{
		ep_str = (char *)((ep_lst_ptr)->data);
		if (*ep_str == '\"')
		{
			expand_in_quote(&ep_str, dict);
			ep_lst_ptr->data = ep_str;
		}
		else if (*ep_str == '$')
		{
			expand(&ep_str, dict);
			ep_lst_ptr->data = ep_str;
		}
		ep_lst_ptr = ep_lst_ptr->next;
	}
}
