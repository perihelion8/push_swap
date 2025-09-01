.PHONY: all clean fclean re

NAME	:=	push_swap

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror

RM		:=	rm -rf

SRC		:=	arri_mem.c arri_modify.c arri_access.c arri_checks.c arri_rules.c arri_lis.c \
		   	queue_mem.c queue_checks.c \
		   	hashset.c \
		   	list_mem.c list_modify.c list_access.c list_checks.c list_rules.c list_bound.c \
		   	put.c \
			parser_args.c parser_validate.c parser_str.c \
			bfs_sort.c bfs_state.c bfs_print.c \
			lis_sort.c lis_cost.c lis_rule.c lis_rule_p.c lis_rule_r.c lis_rule_rr.c lis_rule_s.c \
			main.c
OBJ		:=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
