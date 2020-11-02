SRC     =       ./lib/my/my_putchar.c	\
                ./lib/my/my_put_nbr.c	\
                ./lib/my/my_putstr.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME2	= 	./lib/my/my.h

all:	compil_lib compil_my

compil_lib:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ..

compil_my: 
		cp $(NAME2) ../../include

clean:
		rm -f $(OBJ)

fclean:	clean
		rm libmy.a

