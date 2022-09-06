#PROGRAM NAME-------------------------------------------------------------------

NAME 			= 	philo
NAME_BONUS		=	$(NAME)_bonus

#OPTIONS------------------------------------------------------------------------

#PROJECT HAVE (no:n yes:y)
HAVE_LIBFT		= n

#SYSTEM VAR---------------------------------------------------------------------

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

CFLAGS 			= 	-Wall -Werror -Wextra
CC				= 	gcc
RM				= 	rm -rf
VALG_LEAK		=	valgrind --leak-check=full
UNAME_S		 	= 	$(shell uname -s)
REL_PATH		=	$(shell pwd)
LEAK_CMD		=	leaks --atExit --

#DIRECTORIES--------------------------------------------------------------------

SRCS_DIR 		= 	./src
OBJS_DIR		= 	./obj
LIBFT_DIR		= 	./libft
NAME_DSYM		=	./$(NAME).dSYM

SRCS_DIR_BONUS	= 	./bonus/src
OBJS_DIR_BONUS	= 	./bonus/obj

#FILES--------------------------------------------------------------------------

SRCS_FILES	 	= 	0_main.c \
					1_parcing_err.c \
					2_vars_init_free.c \
					3_philo_routine.c \
					4_philo_action.c \
					free_dbl_ptr.c \
					ft_atoi.c \
					ft_atol.c \
					ft_msleep.c \
					itoa.c \
					utils.c \
					debug_fct.c
					
#SRCS_FILES_BONUS= 	

LIBFT_FILES		= 	libft.a

#FILES VAR----------------------------------------------------------------------
SRCS 			= 	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
SRCS_BONUS		=	$(addprefix $(SRCS_DIR_BONUS)/, $(SRCS_FILES_BONUS))

OBJS 			= 	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS 		= 	$(SRCS_BONUS:$(SRCS_DIR_BONUS)/%.c=$(OBJS_DIR_BONUS)/%.o)

LIBFT 			= 	$(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

LIBFT_LINUX		=	-L$(REL_PATH)/libft -lft

#SYSTEM RULES-------------------------------------------------------------------

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BONUS)/%.o: $(SRCS_DIR_BONUS)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

#COMPILING RULES------------------------------------------------------------------

all : 				init $(NAME)

init:
ifeq ($(HAVE_LIBFT),y)
					@$(MAKE) -s -C $(LIBFT_DIR)
endif
					@mkdir -p $(OBJS_DIR)

$(NAME):			$(OBJS) 
ifeq ($(UNAME_S),Linux)
ifeq ($(HAVE_LIBFT),y)
					@gcc $(CFLAGS) libft/*c $(SRCS) -o $(NAME)
else
					@gcc $(CFLAGS) $(SRCS) -o $(NAME)
endif
else
ifeq ($(HAVE_LIBFT),y)
					@$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS)
else
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
endif
endif
					@echo "$G$(NAME)         compiled$W"
					
$(LIBFT):
					@cd $(LIBFT_DIR)/ && make
					

clean:
ifneq ($(wildcard $(OBJS_DIR)),)					
ifeq ($(HAVE_LIBFT),y)					
					@$(MAKE) -s clean -C $(LIBFT_DIR)
endif
					@$(RM) $(OBJS)
					@$(RM) $(OBJS_DIR)
					@$(RM) $(OBJS_BONUS)
					@$(RM) $(OBJS_DIR_BONUS)
					@echo "$R$(NAME) objects deleted$W"
endif

fclean: 			clean
ifneq ($(wildcard $(NAME)),)
ifeq ($(HAVE_LIBFT),y)						
					@$(MAKE) -s fclean -C $(LIBFT_DIR)
endif
					@$(RM) $(NAME_DSYM)
					@$(RM) $(NAME)
					@$(RM) $(NAME_BONUS)
					@echo "$R$(NAME)         deleted$W"
endif
	
re: 				fclean all

bonus:				init_bonus $(NAME_BONUS)

init_bonus:
ifeq ($(HAVE_LIBFT),y)
					@$(MAKE) -s -C $(LIBFT_DIR)
endif
					@mkdir -p $(OBJS_DIR_BONUS)

$(NAME_BONUS):		$(OBJS_BONUS)
					@gcc $(CFLAGS) libft/*c $(SRCS_BONUS) -o $(NAME_BONUS)
					@echo "$G$(NAME_BONUS) compiled$W"

debug:
ifeq ($(HAVE_LIBFT),y)
					gcc -g $(CFLAGS) libft/*c $(SRCS) -o $(NAME)
else
					gcc -g $(CFLAGS) $(SRCS) -o $(NAME)
endif

#TEST---------------------------------------------------------------------------

simple:
					leaks --atExit -- ./$(NAME) 4 500 200 200 10 

big:
					./$(NAME) 200 500 200 200 100

fast:
					./$(NAME) 100 50 20 20 100

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re bonus init init_bonus debug

