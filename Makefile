# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:33:57 by rdedola           #+#    #+#              #
#    Updated: 2024/12/06 15:22:10 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
NAME		= minishell

# Files
VPATH		= source \
			  source/env \
			  source/parsing/lexer \
			  source/parsing/parser \
			  source/parsing/expander \
			  source/execution/builtins \
			  source/execution/executer \
			  source/execution/executer/preparse_for_loop \
			  source/execution/executer/reparse_for_loop \
			  source/execution/executer/structs \
			  source/system \
			  source/utils \

SRC			= main.c

# Environnement
ENV			= init_env.c \
			  manip_env.c \

# Parsing
LEXER		= count_token.c \
			  tokenizer.c \

PARSER		= parser.c \
			  count_pipe.c \
			  handle_quotes.c \
			  handle_pipes.c \
			  handle_redir.c \
			  union_quote.c \
			  union_words.c \
			  final_sort.c \
			  handle_var_redir.c \

EXPANDER	= expand_var.c \
			  expander.c \

# Execution
BUILTINS	= builtin_cd.c \
			  builtin_echo.c \
			  builtin_env.c \
			  builtin_exit.c \
			  builtin_export1.c \
			  builtin_export2.c \
			  builtin_pwd.c \
			  builtin_unset.c \
			  exe_builtin.c \

EXECUTER	= preparse.c \
			  rep_arg.c \
			  rep_cmd.c \
			  rep_doc.c \
			  rep_end.c \
			  rep_opt.c \
			  rep_rfi.c \
			  rep_rfo.c \
			  reparse.c \
			  st_arg.c \
			  st_cmd.c \
			  st_exe.c \
			  st_tio.c \
			  get_path.c \
			  pipeline.c \
			  init_execution.c \
			  setup_execution.c \
			  wait_status.c \

SYSTEM		= ft_alphasort.c \
			  ft_basename.c \
			  ft_close.c \
			  ft_fork.c \
			  ft_write.c \

# Utils
SRC_UTILS	= main_interface_print.c \
			  print_tester_value.c \
			  sigmacros.c \
			  ft_error.c \
			  ft_ismeta.c \
			  ft_risprint.c \
			  ft_isspace.c \
			  ft_strncpy.c \
			  ft_strncpy_exp.c \
			  ft_strlcpy_exp.c \
			  ft_rlstnew.c \
			  ft_strnlen.c \
			  ft_strllen.c \
			  ft_rstrlen.c \
			  ft_rstrdup.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_freebox.c \
			  ft_lenarray.c \
			  ft_isredir.c \
			  ft_rstrchr.c \
			  ft_ismetatoken.c \
			  ft_rstrjoin.c \
			  ft_ritoa.c \
			  ft_check_fd.c \
			  ft_perror.c \
			  ft_envadd_back.c \
			  ft_arg_to_array.c \
			  ft_env_to_array.c \
			  ft_lstdelone_mod.c \
			  ft_lstsize_env.c \
			  ft_free_fork.c \

SOURCES		= ${SRC} ${SRC_UTILS} ${ENV} ${LEXER} ${PARSER} ${EXPANDER} ${BUILTINS} ${EXECUTER} ${SYSTEM}
OBJECTS		= ${SOURCES:%.c=obj/%.o}

# Variables
CC			= cc
CFLAGS		= -Iincludes -I./libraries/libft -Wall -Wextra -Werror -g
RM			= rm -rf

# Libft
LIBFT_DIR	= ./libraries/libft
LIBFT		= ${LIBFT_DIR}/libft.a

# Colors
DEF_COLOR	= \033[0;39m
COLOR		= \033[1;32m

# Makefilema
all: ${LIBFT} ${NAME}

${NAME}: ${OBJECTS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} ${LIBFT} -lreadline
	@echo "${COLOR}╔══════════════════════════╗${DEF_COLOR}"
	@echo "${COLOR}║    Minishell compiled    ║${DEF_COLOR}"
	@echo "${COLOR}╚══════════════════════════╝${DEF_COLOR}"

${LIBFT}:
	@make -C ${LIBFT_DIR} --no-print-directory

obj/%.o: %.c
	@mkdir -p obj/$(dir $<)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} obj
	@make -C ${LIBFT_DIR} clean --no-print-directory
	@echo "${COLOR}╔══════════════════════════╗${DEF_COLOR}"
	@echo "${COLOR}║    Minishell cleaned!    ║${DEF_COLOR}"
	@echo "${COLOR}╚══════════════════════════╝${DEF_COLOR}"

fclean: clean
	@${RM} ${NAME}
	@make -C ${LIBFT_DIR} fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
