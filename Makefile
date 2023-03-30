# The name of your executable
NAME		= ft_ping

# Compiler and compiling flags
CC	= gcc
CFLAGS	= -Iinc #-Wall -Werror -Wextra

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3
endif
ifeq ($(DEBUG),2)
CFLAGS	+= -g3 -fsanitize=address -fno-omit-frame-pointer
endif
ifeq ($(DEBUG),3)
CFLAGS	+= -g3 -fsanitize=leak
endif

# Folder name
SRCDIR	= src/
OBJDIR	= bin/
HDRDIR	= inc/

INCLUDES = $(addprefix $(HDRDIR), \
	header.h\
)
# Add the path to your source files in the src folder
SRCS = $(addprefix $(SRCDIR), \
	main.c get_addr_info.c create_socket.c\
)

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# ================================== RULES =================================== #

all : $(NAME)

# Compiling
$(OBJDIR)%.o : $(SRCDIR)%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $< -o $@  $(INCLUDES_MAC)

# Linking
$(NAME)	: $(SRCS)  $(OBJS) $(INCLUDES)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC)$(RC)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Cleaning
clean :
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -rf $(NAME)

# Special rule to force to remake everything
re : fclean all

# This runs the program
run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

# This specifies the rules that does not correspond to any filename
.PHONY	= all run clean fclean re
