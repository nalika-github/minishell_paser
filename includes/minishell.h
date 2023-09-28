/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/28 20:50:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Standard Header  */

# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>

/* Common Header  */
# include "libft.h"
# include "libminishell.h"

/* text color */
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define PUR "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

/* bold text color */

#define REDB "\e[1;31m"
#define GRNB "\e[1;32m"
#define YELB "\e[0;33m"
#define BLUB "\e[1;34m"
#define PURB "\e[1;35m"
#define CYNB "\e[1;36m"
#define WHTB "\e[1;37m"

/* token and tag_ctrl index define*/

# define EMPTY 0
# define CMD 1
# define ARG 2
# define FPATH 3
# define INFILE 4
# define OUTFILE 5
# define HEREDOC 6
# define PIPE 7
# define APPEND 8

/* tag_ctrl index define*/

# define START 9
# define IFBFCMD 10
# define OFBFCMD 11
# define HDBFCMD 12
# define APBFCMD 13
# define FPBFCMD 14
# define EXPAND 14

enum e_prterr
{
	CANNT_PIPE,
	CANNT_FORK,
	CANNT_OPENIN,
	CANNT_OPENOUT,
	PER_DN,
	CANNT_OPEN
};

enum e_typestrjoin
{
	BEFORE,
	AFTER,
	BEFOREANDAFTER,
	NONE
};

enum e_prtexec
{
	ERR_PATH,
	ERR_CMD
};

/* error index define*/

# define EXIT_SUCCESS 0
# define ERRPASER 2

/*  Define Structure  */

typedef struct	s_token
{
	int		type;
	char	*str;
}				t_token;

typedef struct s_dict_value
{
	char *key;
	char *value;
} t_dict_value;

typedef struct s_dict
{
	t_dict_value *tmp_dict;
	struct s_dict *next;
} t_dict;

typedef struct	s_rdr
{
	int		type;
	char	*file;
}				t_rdr;

typedef struct	s_table
{
	t_list	*rdr; // redirect
	char	**cmd;
}				t_table;

typedef struct	s_minishell
{
	t_list	*tk_lst;
	t_list	*tb_lst;
	char	**my_env;
	t_dict	*dict;
	int		index;
	int		exit_code;
}				t_minishell;

/*  prompt.c  */

char	*prompt(void);

/*  lexer.c  */

int		lexer(char *line, t_minishell *env);

/*  init_minishell.c  */

// t_minishell	init_minishell();

/*  init_command_list.c  */

int		slide_n_decide(t_list *lst, char *line);
int		init_command_list(t_minishell **env, char *line);

/*  grab.c  */

size_t	arg_logic(char *line);
size_t	quote_logic(char *line);
size_t	metachar_logic(char *line);
char	*grab_n_slide(char **line, size_t (*logic)(char *));
void	grab_to_lst(t_list **lst, char **line, int index);

/*  tokenize  */

int	tokenize(t_minishell **env);

/*  quotes_validate.c  */

int	quotes_validate(t_minishell *env);

/*  paser.c  */

int	paser(t_minishell *ms);

/*  get_cmd_to_table.c  */

int	get_cmd_to_table(t_minishell **ms);

/*  get_rdr_to_table.c  */

int	get_rdr_to_table(t_minishell **ms);

/*  scan_n_expand.c  */

void	scan_n_expand(t_list **ep_lst, t_dict *dict);

/*  expand_var.c  */

int	expand_var(t_minishell **ms);

#endif
