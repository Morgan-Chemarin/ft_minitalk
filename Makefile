NAME_SERVER = server
NAME_CLIENT = client

SRCS_CLIENT = src/client.c src/utils.c
SRCS_SERVER = src/server.c src/utils.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iinclude

PRINTF_DIR = ft_printf
PRINTF_LIB = ${PRINTF_DIR}/libftprintf.a
PRINTF_INC = -I${PRINTF_DIR}

all: ${NAME_SERVER} ${NAME_CLIENT}

src/%.o: src/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME_SERVER}: ${OBJS_SERVER} ${PRINTF_LIB}
	${CC} ${CFLAGS} ${PRINTF_INC} ${OBJS_SERVER} -L${PRINTF_DIR} -lftprintf -o ${NAME_SERVER}

${NAME_CLIENT}: ${OBJS_CLIENT} ${PRINTF_LIB}
	${CC} ${CFLAGS} ${PRINTF_INC} ${OBJS_CLIENT} -L${PRINTF_DIR} -lftprintf -o ${NAME_CLIENT}

clean:
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
	
fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re
