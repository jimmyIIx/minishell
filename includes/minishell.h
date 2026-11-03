/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:33:10 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 15:22:07 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define RED		"\001\033[31;1m\002"
# define GREEN		"\001\033[32;1m\002"
# define YEL		"\001\033[33;1m\002"
# define PURP		"\001\033[35;1m\002"
# define ENDCL		"\001\033[0m\002"

# define MAX_OUTPUT_LENGHT 1024

extern int	g_exit_status;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef enum e_token
{
	WSPACE,				// Whitespace
	WORD,				// Others
	SINGLE_QUOTE,		// '
	DOUBLE_QUOTE,		// "
	PIPE,				// |
	REDIN,				// <
	REDOUT,				// >
	HEREDOC,			// <<
	APPEND_REDIR,		// >>
	DOLLAR,				// $
	NA,					// NULL token
	END,				// End of the array
}	t_token;

//ENV chained list.
typedef struct s_env
{
	char			*name;
	char			*arg;
	t_bool			is_egal;
	bool			is_format;
	struct s_env	*next;
}	t_env;

//Terminal struct.
typedef struct s_tio
{
	struct termios	old;
	struct termios	new;
}	t_tio;

//Lexer struct.
typedef struct s_lexer
{
	int			nb_of_tokens;
	int			*tokens;
	char		**tokens_array;
}	t_lexer;

//Parser struct.
typedef struct s_parser
{
	int			nb_pipe;
}	t_parser;

//Main struct.
typedef struct s_ms
{
	t_env		*env;
	t_lexer		lexer;
	t_parser	parser;
	char		*input;
	char		**env_array;
	t_bool		is_env;
	bool		is_error;
	bool		is_exit;
}	t_ms;

//Pipe struct.
typedef struct s_exe
{
	int			fds[2];
	int			pipe_base[2];
	int			pipe_here[2];
	int			fd_i;
	int			fd_o;
	bool		is_strict;
	bool		is_exit;
}	t_exe;

//Flags.
typedef struct s_arg
{
	char		arg[BUFSIZ];
	int			type;
	bool		is_strict;
}	t_arg;

//Execut struct.
typedef struct s_cmd
{
	pid_t		pid;
	t_list		*arg;
	char		cmd[BUFSIZ];
	char		nme[BUFSIZ];
	char		rfi[BUFSIZ];
	char		rfo[BUFSIZ];
	char		doc[BUFSIZ];
	char		path[BUFSIZ];
	bool		has_file_i;
	bool		has_file_o;
	bool		has_pipe_i;
	bool		has_pipe_o;
	bool		has_option;
	bool		is_builtin;
	bool		has_heredoc;
	bool		is_finished;
	size_t		count;
}	t_cmd;

/******************************************************************************
 *                                   E N V                                    *
******************************************************************************/

// Initialize the environment variables.
void	init_env(t_ms *ms, char **envp);
// Check \ character in the string.
bool	ft_is_formated(char *arg);

/******************************************************************************
 *                                 L E X E R                                  *
******************************************************************************/

// Count the number of pipes in the input.
void	count_pipe(t_ms *ms);
// Count the number of tokens in the input.
int		count_token(t_ms *ms);
// Split and categorize each element of the input in a **array with its token.
void	tokenizer(t_ms *ms, int x, int y);

/*******************************************************************************
 *                                P A R S E R                                  *
*******************************************************************************/

// Free the old output and write the new one without NA tokens or WSPACE tokens.
void	final_sort(t_ms *ms);
// Check if a PIPE is surrounded by WORDS.
t_bool	handle_pipes(t_ms *ms);
// Check if REDIR is followed by WORD.
t_bool	handle_redir(t_ms *ms);
// Parse and convert all tokens in "" or '' in a WORD token (except $) in "".
t_bool	handle_quote(t_ms *ms, t_env *env, int singleq, int doubleq);
// Handle variable redirection.
t_bool	handle_var_redir(t_ms *ms);
// Main file for the parsing.
t_bool	parser(t_ms *ms, t_env *env);
// Join in one token all the string between "" or ''.
void	union_quote(t_ms *ms, int i, int j);
// Union all words who are not separated by a WSPACE or NA token.
void	union_words(t_ms *ms, int i);

/******************************************************************************
 *                              E X P A N D E R                               *
******************************************************************************/

// Add the variable only if it does not exist.
void	add_var(char *name, char *new, bool egal, t_env *env);
// Expander module dissociated for handle expander in handle_quote function.
void	expand_var(t_ms *ms, t_env *env, int i);
// Expander module for the $? var.
void	expand_retvar(t_ms *ms, int i);
// Main core of the expander for all the input string.
void	expander(t_ms *ms, t_env *env);
// Modify or add an environment variable.
void	modify_var(char *name, char *new, bool egal, t_env *env);
// Search the var in the env chained list.
char	*search_var(char *str, t_env *env);

/******************************************************************************
 *                              B U I L T I N S                               *
******************************************************************************/

// Implementation of the cd built-in command.
int		builtin_cd(t_cmd *cmd, t_ms *ms);
// Implementation of the echo built-in command.
int		builtin_echo(t_cmd *cmd);
// Implementation of the env built-in command.
int		builtin_env(t_env *env);
// Implementation of the exit built-in command.
int		builtin_exit(t_cmd *cmd, t_ms *ms);
// Implementation of the export built-in command.
int		builtin_export(t_cmd *cmd, t_ms *ms);
// Implementation of the pwd built-in command.
int		builtin_pwd(t_ms *ms);
// Implementation of the unset built-in command.
int		builtin_unset(t_cmd *cmd, t_ms *ms);
// Execute the built-in command.
int		exe_builtin(t_cmd *cmd, t_ms *ms);

/******************************************************************************
 *                             E X E C U T I O N                              *
******************************************************************************/

// Initialize execution.
char	**init_execution(t_cmd *cmd);
// Close the file descriptor.
int		ft_close(int *fd);
// Fork the process.
pid_t	ft_fork(int *pid);
// Execute the command.
void	execute(t_ms *ms);
// Get the path of the command.
bool	get_path(t_cmd *cmd, t_ms *ms);
// Initialize the argument structure.
void	st_arg_init(t_arg *arg);
// Clear the argument structure.
void	st_arg_clear(t_arg *arg);
// Initialize the command structure.
void	st_cmd_init(t_cmd *cmd);
// Clear the command structure.
void	st_cmd_clear(t_cmd *cmd);
// Initialize the execution structure.
void	st_exe_init(t_exe *exe);
// Clear the execution structure.
void	st_exe_clear(t_exe *exe);
// Initialize the tio structure.
void	st_tio_init(t_tio *tio);
// clear the tio structure..
void	st_tio_clear(t_tio *tio);
// Close the pipeline.
void	pipeline_close(t_exe *exe, t_cmd *cmd);
// Open the pipeline.
void	pipeline_open(t_exe *exe, t_cmd *cmd, bool close);
// Prepare for parsing.
void	preparse(t_ms *ms);
// Reparse the command.
void	reparse(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
// Replace the argument.
void	rep_arg(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
// Replace the command.
void	rep_cmd(t_ms *ms, t_cmd *cmd, size_t index);
// Replace the end.
void	rep_end(t_ms *ms, t_cmd *cmd, size_t index);
// Replace the heredoc.
void	rep_doc(t_ms *ms, t_cmd *cmd, size_t index);
// Replace the option.
void	rep_opt(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
// Replace the redirection file in.
void	rep_rfi(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
// Replace the redirection file out.
void	rep_rfo(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
// Check if the token is an argument.
bool	rep_is_arg(t_ms *ms, t_cmd *cmd, size_t index);
// Check if the token is a command.
bool	rep_is_cmd(t_ms *ms, t_cmd *cmd, size_t index);
// Check if the token is a heredoc.
bool	rep_is_doc(t_ms *ms, t_cmd *cmd, size_t index);
// Check if the token is an end.
bool	rep_is_end(t_ms *ms, t_cmd *cmd, size_t index);
// Check if the token is an option.
bool	rep_is_opt(t_ms *ms, t_cmd *cmd, size_t index);
// Check if the token is a redirection file in.
bool	rep_is_rfi(t_ms *ms, t_cmd *cmd, size_t index);
// Check if the token is a redirection file out.
bool	rep_is_rfo(t_ms *ms, t_cmd *cmd, size_t index);

/******************************************************************************
 *                                 U T I L S                                  *
******************************************************************************/

// Scandir entries alphabetically using
int		ft_alphasort(void *a, void *b);
// Count the nb of char* un a char**.
int		ft_lenarray(char **array);
// Count and return the nb of char form the specified char to the end.
int		ft_strllen(char *str, char c);
// Count and return the nb of char up to the specified char.
int		ft_strnlen(char *str, char c);
// Count and return the nb of character in a string.
int		ft_rstrlen(char *str);
// Create a new chained list.
t_env	*ft_rlstnew(char *name, char *arg, bool is_egal);
// Compare two strings and return TRUE if they are the same, or FALSE if not.
t_bool	ft_strcmp(char *str1, char *str2);
// Copy the src string in the dest string.
char	*ft_strcpy(const char *src, char *dest);
// Copy the *src in the *dest of x size.
char	*ft_strncpy(char *src, char *dest, int size);
// Copy the the string from the specified char to the end. Only for expander.
char	*ft_strlcpy_exp(char *src, char c);
// Copy the the string up to the specified char. Only for expander function.
char	*ft_strncpy_exp(char *str, char c);
// Duplicate with malloc a string.
char	*ft_rstrdup(char *str);
// Free the **env_array, copy of **envp.
void	free_envarray(t_ms *ms, char **envp);
// Free the chained list who contained all the ENV values.
void	free_env(t_env *env);
// Free the int* tokens, and the char** token_array.
void	free_tok(t_ms *ms);
// Handle Ctrl + C.
void	handle_macro(int sig);
// Handle
void	handle_ignore(int sig);
// Handle Ctrl + C.
void	handle_macro_cct(int sig);
// Handle MACRO
void	handle_macro_rtm(int sig);
// Handle Ctrl + \\.
void	handle_sigquit(int sig);
// Handle error messages.
t_bool	ft_error(char *str);
// Check fd
void	ft_check_fd(void);
// Check if the accurate char is a meta char.
t_bool	ft_ismeta(char c);
// Check if the accurate char is a redirection char.
t_bool	ft_isredir(t_ms *ms, int i);
// Check if the token is a meta token.
t_bool	ft_ismeatoken(t_ms *ms, int i);
// Check if the accurate char is a printable char.
t_bool	ft_risprint(int c);
// Check if the accurate char is a space char.
t_bool	ft_isspace(char c);
// Search c in *str and return TRUE if c is found.
t_bool	ft_rstrchr(char *str, char c);
// Join two strings.
char	*ft_rstrjoin(char *src, char *add);
// Convert an integer to a string.
char	*ft_ritoa(int n);
// Convert the argument list to an array.
char	**ft_arg_to_array(t_list *list);
// Convert the environment list to an array.
char	**ft_env_to_array(t_env *list);
// Add a new node to the environment list.
void	ft_envadd_back(t_env **env, t_env *new);
// Delete a node from the environment list.
void	ft_lstdelone_mod(t_env *lst, void (*del)(void*));
// Get the base name of a path.
void	ft_basename(const char *path, char *result);
// Get the size of the environment list.
int		ft_lstsize_env(t_env *lst);
// The MINISHELL menu printer.
void	main_interface_print(void);
// The temp file for test all the values.
void	print_tester_value(t_ms *ms);
// Print an error message.
void	ft_perror(const char *shell, char const *cmd, char const *arg,
			char const *msg);
// Wait for the command to finish.
void	wait_status(t_cmd *cmd);
// Write a string to a file descriptor.
void	ft_write(int fd, const char *str);
// Free fork
void	ft_free_fork(char **earg, char **eenv);

// Main file.
int		main(int __attribute__((unused)) argc,
			char __attribute((unused)) **argv, char **envp);

#endif
