NAME = lem-in

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = obj/

FILES = algorithm	algorithm2	algorithm3	block \
check	free	lem_in	reading_data1	reading_data2	reading_data3\
print	handle_errors	print2	check_room	width_search find_room
SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(FILES)))
OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(FILES)))

LIBFT = ./libft/libftprintf.a 
INCDIR = -I ./includes
LIBLINK = -L ./libft -lftprintf
LIBINC = -I ./libft/includes

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C ./libft

$(OBJDIR):
	@echo "Creating Lem-in object files directory..."
	@mkdir $(OBJDIR)
	@echo "Directory created!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(FLAGS) $(INCDIR) $(LIBINC) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling Lem-in..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
	@echo "Lem-in is compiled!"

libclean:
	@make clean -C ./libft

clean: libclean
	@echo "Deleting Lem-in object files..."
	@rm -rf $(OBJDIR)
	@echo "Lem-in object files are deleted!"

fclean: clean
	@echo "Deleting lem-in executable..."
	@rm -rf $(NAME)
	@echo "Executable is deleted!"
	@make fclean -C ./libft
	@echo "Everything is cleaned!"

re: fclean
	@$(MAKE) all

test-bigs:
	./generator --big-superposition > test1; ./lem-in < test1

test-big:
	./generator --big > test1; ./lem-in < test1