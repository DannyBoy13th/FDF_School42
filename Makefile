# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 15:23:54 by dsoloshe          #+#    #+#              #
#    Updated: 2017/04/04 15:23:56 by dsoloshe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = validator.c launcher.c operations.c draw_image.c key_hooks.c

OBJ = validator.o launcher.o operations.o draw_image.o key_hooks.o

FLAGS = -Wall -Wextra -Werror

LIBCOMP = cd libft && make && cd ..
LIBCLEAN = cd libft && make clean && cd ..
LIBFCLEAN = cd libft && make fclean && cd ..

MLGCC = gcc -o fdf -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(CDTOLIB)
	$(LIBCOMP)
	$(LIBCLEAN)
	$(CDBACK)
	$(MLGCC) $(FLAGS) $(SRC) libft/libft.a

clean:
	$(LIBCLEAN)
	rm -rf $(OBJ)

fclean:	clean
	$(LIBFCLEAN)
	rm -rf $(NAME)

re:	fclean all
