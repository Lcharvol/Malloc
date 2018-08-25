ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =	libft_malloc_$(HOSTTYPE).so
LINK =	libft_malloc.so

CC =	gcc
FLAGS =	-Wall -Wextra

SRC_DIR =	src
OBJ_DIR =	.obj
INC_DIR =	includes

SRC =	malloc.c\
		show_mem.c\
		show_content.c\
		container.c\
		allocations.c\

OBJ =	$(SRC:%.c=$(OBJ_DIR)/%.o)

INC =	prototypes.h

INCLUDE =	$(INC:%.h=$(INC_DIR)/%.h)

LIBFT =	libft

.PHONY: clean fclean all re norme newline $(LIBFT)/libft.a

# .SILENT:

all: $(NAME)

newline:
	@echo "\033[38;5;166m\033[0m\n"

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) | $(OBJ_DIR)
	@echo "\033[1A\033[K\033[38;5;226mmaking $@\033[0m"
	@$(CC) $(FLAGS) -fPIC -I include -I $(LIBFT)/include -o $@ -c $<

$(NAME): $(LIBFT)/libft.a newline $(OBJ)
	@echo "\033[1A\033[K\033[38;5;214mmaking $@\033[0m"
	@$(CC) $(FLAGS) -shared -I include -I $(LIBFT)/include -o $(NAME) $(OBJ) -L $(LIBFT) -lft -lpthread
	@ln -sf $(NAME) $(LINK)
	@echo "\033[1A\033[K\033[32;5;214m$@ => created \033[0m\n"

clean:
	@rm -f $(OBJ)
	@echo "\033[1A\033[K\033[38;5;01mObject files => deleted\033[0m\n"
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME) $(LINK)
	@echo "\033[1A\033[K\033[38;5;01m$(NAME) => deleted\033[0m\n"
	@make -C $(LIBFT) fclean

re: fclean all

norme: newline
	norminette $(OBJ:.o=.c) include