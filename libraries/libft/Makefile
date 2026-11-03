# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:49:45 by nippolit          #+#    #+#              #
#    Updated: 2025/03/18 16:41:15 by nippolit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_obligatoire    =   gnl/get_next_line.c \
						gnl/get_next_line_utils.c\
						ft_isalpha.c      \
						ft_isdigit.c      \
						ft_isalnum.c      \
						ft_isascii.c      \
						ft_isprint.c      \
						ft_strlen.c       \
						ft_memset.c       \
						ft_bzero.c        \
						ft_memcpy.c       \
						ft_memmove.c      \
						ft_strlcpy.c      \
						ft_strlcat.c      \
						ft_toupper.c      \
						ft_tolower.c      \
						ft_strchr.c       \
						ft_strrchr.c      \
						ft_strncmp.c      \
						ft_memchr.c       \
						ft_memcmp.c       \
						ft_strnstr.c      \
						ft_atoi.c         \
						ft_calloc.c       \
						ft_strdup.c       \
						ft_substr.c       \
						ft_strjoin.c      \
						ft_itoa.c         \
						ft_strtrim.c      \
						ft_split.c        \
						ft_striteri.c     \
						ft_putchar_fd.c   \
						ft_putstr_fd.c    \
						ft_putendl_fd.c   \
						ft_strmapi.c      \
						ft_putnbr_fd.c    \
						ft_strjoin_mod.c  \
						ft_free.c         \
						ft_free_deep.c    \
						ft_lstadd_front.c \
						ft_lstsize.c      \
						ft_lstlast.c      \
						ft_lstadd_back.c  \
						ft_lstdelone.c    \
						ft_lstclear.c     \
						ft_lstiter.c      \
						ft_lstmap.c       \
						ft_lstcmp.c       \
						ft_lstnew.c       \
						ft_strcat.c       \
						ft_qsort.c        \
						ft_ternary.c      \
						ft_lst_to_array.c \
						ft_str_other.c	  \


NAME 	= 	libft.a

INCLUDE	=	-I.

CC	 	= 	clang

CFLAGS	=  -Wall -Wextra -Werror -c

CCF		=	${CC} ${CFLAGS}

SRCS 	=	${SRCS_obligatoire}

SRCALL  =	${SRCS_obligatoire}

OBJS    =	${SRCS:.c=.o}

OBJSALL =	${SRCALL:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
		@ar -rsc ${NAME} ${OBJS}

bonus   : ${OBJSALL}
		@ar -rsc ${NAME} ${OBJS} ${OBJSALL}

%.o : %.c
		@${CCF} ${INCLUDE} $< -o $@
		@printf "$(MSG_BCOLOR_WARNING)compilation: $< !$(TERM_CONTROL_RESET)\n"

clean  :
		@rm -f ${OBJS} ${OBJSALL}
		@printf "$(MSG_BCOLOR_FAILURE)clean: libft !$(TERM_CONTROL_RESET)\n"

fclean : clean
		@rm -f ${NAME}

re     : fclean all




# >>>>>>>>>> MESSAGES COLORS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 MSG_BCOLOR_FAILURE		:=	\001\e[1;31m\002 # Rouge gras
 MSG_BCOLOR_LOGGING		:=	\001\e[1;37m\002 # Blanc gras
 MSG_BCOLOR_SUCCESS		:=	\001\e[1;32m\002 # Vert  gras
 MSG_BCOLOR_WARNING		:=	\001\e[1;33m\002 # Jaune gras

# >>>>>>>>>> TERMINAL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 TERM_CONTROL_CLEAR		:=	\001\e[1;1H\e[2J\002
 TERM_CONTROL_RESET		:=	\001\e[0m\002



