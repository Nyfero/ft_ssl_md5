#    Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

#    Showing command
DISP = FALSE

ifeq ($(DISP),TRUE)
    HIDE =
else
    HIDE = @
endif

#    Includes
INC_PATH = inc/

INC = $(addprefix $(INC_PATH), ft_ssl.h)

#	 Lib
LIB_DIR = Libft/

LIB = $(LIB_DIR)/libft.a

#    Folders
SRCS_PATH = srcs

MD5_PATH = md5

SHA256_PATH = sha256

UTILS_PATH = utils

#    Files
FILES = main.c

MD5 = $(addprefix $(MD5_PATH)/, md5_init.c)

SHA256 =

UTILS = $(addprefix $(UTILS_PATH)/, print_message.c)

#    Compilation
NAME = ft_ssl

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = $(addprefix $(SRCS_PATH)/,	$(FILES) $(MD5) $(UTILS))

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c $(MD5_PATH)%.c $(UTILS_PATH)%.c,	$(OBJS_PATH)%.o,	$(SRCS))

#    Rules
all: $(NAME)

$(NAME): $(LIB) $(OBJS_PATH) $(OBJS) $(INC)
	@ echo "$(BLUE)\n         ***Make $(NAME) ***\n$(END)"
	$(HIDE) $(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm $(LIB)
	@ echo "$(GREEN)\n        ---$(NAME) created ---\n$(END)"

$(LIB): $(LIB_DIR)/Makefile
	@ echo "$(BLUE)\n        ***Make libft.a ***\n$(END)"
	$(HIDE) make -C $(LIB_DIR)

$(OBJS_PATH):
	$(HIDE) mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(MD5_PATH)%.c $(UTILS_PATH)%.c $(INC) Makefile
	$(HIDE) $(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

clean:
	@ echo "$(PURPLE)\n        *** Clean objects ***\n$(END)"
	$(HIDE) $(RM) $(OBJS_PATH)
	$(HIDE) make clean -C $(LIB_DIR)

fclean: clean
	$(HIDE) $(RM) $(NAME)
	$(HIDE) make fclean -C $(LIB_DIR)
	@ echo "$(RED)\n        *** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re