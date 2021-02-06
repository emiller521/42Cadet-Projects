
NAME	= ft_ls

SRC		=	main.c \
			sort.c \
			handle_args.c \
			helpers.c \
			printer.c \
			ls.c

ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -O3 -march=native -funroll-loops

LIBFT	= ./Libft/Libft/libft.a
LIBINC	= -I./Libft/Libft
LIBLINK	= -L./Libft/Libft -lft

PRINTF	= ./b_printf/libftprintf.a
PFINC	= -I./b_printf
PFLINK	= -L./b_printf -lftprintf

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj Libft b_printf $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) $(PFINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

printf: $(PRINTF)

$(LIBFT):
	make -C ./Libft/Libft

$(PRINTF):
	make -C ./b_printf

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(LIBLINK) $(PFLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./Libft/Libft clean
	make -C ./b_printf clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
