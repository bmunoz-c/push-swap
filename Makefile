# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:39:48 by bmunoz-c          #+#    #+#              #
#    Updated: 2024/05/23 17:48:50 by bmunoz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

SRC =		main_function.c push_swap_cmds.c \
			ft_check_args.c \
			stack_init.c stack_utils.c \
			algorithm.c ft_algorithm_utils.c \
			swap_cmd.c rotate_cmd.c reverse_rotate_cmd.c push_cmd.c \
			free_error.c \

#----COLORS----#
DEF_COLOR = \033[1;39m
WHITE_BOLD = \033[1m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CIAN = \033[1;36m

#----DIRECTORIES----#
BIN_DIR =	bin/

#----BINARIES----#
OBJS =		$(SRC:%.c=$(BIN_DIR)%.o)
DEPS =		$(OBJS:%.o=%.d)

#----COMMANDS----#
AR =		ar rcs
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f

#----TARGETS----#
all: $(NAME)

$(NAME): $(OBJS)
	@cc $(OBJS) -o $(NAME)
	@echo "$(BLUE)Objects linked and executable $(RED)$(NAME) $(BLUE)created!$(DEF_COLOR)"

$(BIN_DIR)%.o: %.c Makefile
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "$(WHITE_BOLD)Object$(YELLOW) $@ $(GREEN)compiled!$(DEF_COLOR)"

clean:
	@$(RM) -rf $(BIN_DIR)
	@echo "$(GREEN)Clean successfull!$(DEF_COLOR)"

fclean:
	@$(RM) -rf $(BIN_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)Full clean successfull!$(DEF_COLOR)"

re:			fclean all

-include $(DEPS)

.PHONY: all clean fclean re dir
