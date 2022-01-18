# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 10:57:50 by lmaujean          #+#    #+#              #
#    Updated: 2022/01/18 17:48:03 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################################################
#                            BASIC DECLARATION                                #
#############################################################################
NAME				= philo
CC					= clang
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror #-g -fsanitize=address

#############################################################################
#                            DECLARATION                                        #
#############################################################################
HEADER_SRC	=	includes/philo.h

FOLDER		=	srcs/

SRCS		=	main.c\
				pars.c\
				utils.c\
				start.c\
				utils2.c\
				life.c\



SRC			=	$(addprefix ${FOLDER}, ${SRCS})

OBJS		=	${SRC:.c=.o}

OBJ			=	${OBJS}

HEADER		=	${HEADER_SRC}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -lpthread -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

%.o: %.c	${HEADER}
			${CC} ${CFLAGS} -c -o $@ $<

norm:
			norminette includes/ srcs/

.PHONY:		all clean fclean re norm