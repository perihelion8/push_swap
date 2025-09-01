.PHONY: all clean fclean re

NAME		:=	push_swap
NAME_BONUS	:=	checker

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror

RM			:=	rm -rf

SRC			:=	arri_mem.c arri_modify.c arri_access.c arri_checks.c arri_rules.c arri_lis.c \
		   		queue_mem.c queue_checks.c \
		   		hashset.c \
		   		list_mem.c list_modify.c list_access.c list_checks.c list_rules.c list_bound.c \
		   		put.c \
				parser_args.c parser_validate.c parser_str.c \
				bfs_sort.c bfs_state.c bfs_print.c \
				lis_sort.c lis_cost.c lis_rule.c lis_rule_p.c lis_rule_r.c lis_rule_rr.c lis_rule_s.c \
				main.c
OBJ			:=	$(SRC:.c=.o)

SRC_BONUS	:=	bonus/arri_access_bonus.c bonus/arri_mem_bonus.c bonus/arri_modify_bonus.c \
				bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
				bonus/hashset_bonus.c bonus/put_bonus.c \
				bonus/list_access_bonus.c bonus/list_checks_bonus.c bonus/list_mem_bonus.c \
				bonus/list_modify_bonus.c bonus/list_rules_bonus.c \
				bonus/parser_args_bonus.c bonus/parser_rule_bonus.c bonus/parser_str_bonus.c bonus/parser_validate_bonus.c \
				bonus/main_bonus.c
OBJ_BONUS	:= 	$(SRC_BONUS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) 

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all
