/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/24 00:04:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include <stddef.h>

/*  libft_minisell  */

int	ft_ismetachar(char c);
int	ft_isquote(char c);
int	ft_isvalide_quote(char *str);

#endif
