# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shoque <shoque@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 06:59:13 by farhan            #+#    #+#              #
#    Updated: 2025/11/18 16:42:46 by shoque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRCS = 	$(SRC_DIR)/Operations/ft_push.c \
		$(SRC_DIR)/Operations/ft_swap.c \
		$(SRC_DIR)/Operations/ft_rotate.c \
		$(SRC_DIR)/Operations/ft_rev_rotate.c \
		$(SRC_DIR)/Operations/ft_sort_stacks.c \
		$(SRC_DIR)/Operations/ft_sort_utils.c \
		$(SRC_DIR)/Operations/ft_sort_three.c \
		$(SRC_DIR)/Push_swap/ft_abs.c \
		$(SRC_DIR)/Push_swap/ft_current_index.c \
		$(SRC_DIR)/Push_swap/ft_error.c \
		$(SRC_DIR)/Push_swap/ft_find_cheapest_node.c \
		$(SRC_DIR)/Push_swap/ft_find_end.c \
		$(SRC_DIR)/Push_swap/ft_find_max.c \
		$(SRC_DIR)/Push_swap/ft_find_min.c \
		$(SRC_DIR)/Push_swap/ft_find_target_node.c \
		$(SRC_DIR)/Push_swap/ft_free_stack.c \
		$(SRC_DIR)/Push_swap/ft_is_sorted.c \
		$(SRC_DIR)/Push_swap/ft_prep_for_push.c \
		$(SRC_DIR)/Push_swap/ft_set_cost.c \
		$(SRC_DIR)/Push_swap/ft_stack_len.c \
		$(SRC_DIR)/Push_swap/init_nodes_a.c \
		$(SRC_DIR)/Push_swap/init_nodes_b.c \
		$(SRC_DIR)/Push_swap/main.c \
		$(SRC_DIR)/Push_swap/ft_split.c \
		$(SRC_DIR)/Push_swap/ft_split_utils.c \
		$(SRC_DIR)/Push_swap/parsing.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I$(INC_DIR)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
INCLUDES += -I$(FT_PRINTF_DIR)
LIBS = -L$(FT_PRINTF_DIR) -lftprintf

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/Operations
	@mkdir -p $(OBJ_DIR)/Push_swap

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(FT_PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re