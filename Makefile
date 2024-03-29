#! ******************************************************************************#
#                                   NAME                                         #
#! ******************************************************************************#

NAME = push_swap
NAME_BONUS = checker
.DEFAULT_GOAL := all
.PHONY: all clean fclean re bonus
.SILENT:

#! ******************************************************************************#
#                                   COLORS                                       #
#! ******************************************************************************#

BLACK=\033[30m
DARK_RED=\033[31m
DARK_GREEN=\033[32m
DARK_YELLOW=\033[33m
DARK_BLUE=\033[34m
DARK_MAGENTA=\033[35m
DARK_CYAN=\033[36m
LIGHT_GRAY=\033[37m
DARK_GRAY=\033[90m
RED=\033[91m
GREEN=\033[92m
ORANGE=\033[93m
BLUE=\033[94m
YELLOW = \033[33m
MAGENTA=\033[95m
CYAN=\033[96m
WHITE=\033[97m
BG_DEFAULT=\033[49m
BG_BLACK=\033[40m
BG_DARK_RED=\033[41m
BG_DARK_GREEN=\033[42m
BG_DARK_YELLOW=\033[43m
BG_DARK_BLUE=\033[44m
BG_DARK_MAGENTA=\033[45m
BG_DARK_CYAN=\033[46m
BG_LIGHT_GRAY=\033[47m
BG_DARK_GRAY=\033[100m
BG_RED=\033[101m
BG_GREEN=\033[102m
BG_ORANGE=\033[103m
BG_BLUE=\033[104m
BG_MAGENTA=\033[105m
BG_CYAN=\033[106m
BG_WHITE=\033[107m
FCOLOR = \033[0m

#! ******************************************************************************#
#                                   PATH                                         #
#! ******************************************************************************#

SRCS_PATH = src/
SRCS_BONUS_PATH = src/bonus/
INCS_PATH = include/ lib/libft/include/
BUILD_DIR := build/
LIBFT_DIR := lib/libft/

#! ******************************************************************************#
#                                   FILES                                        #
#! ******************************************************************************#

SRCS =	$(addprefix $(SRCS_PATH), \
		compare.c \
		cost.c \
		main.c \
		pivot.c \
		push.c \
		quick_sort.c \
		rank.c \
		rotate.c \
		rotate_rever.c \
		sort_big.c \
		stack_build.c \
		swap.c \
		utils.c \
		utils_rank.c \
		validation.c)

SRC_BONUS = $(addprefix $(SRCS_BONUS_PATH), \
		checker.c \
		utils_checker.c) \
		$(addprefix $(SRCS_PATH), \
		pivot.c \
		push.c \
		quick_sort.c \
		rank.c \
		rotate.c \
		rotate_rever.c \
		sort_big.c \
		stack_build.c \
		swap.c \
		utils.c \
		utils_rank.c \
		compare.c \
		cost.c \
		validation.c)

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
LIBS := $(LIBFT_DIR)libft.a
OBJS = $(SRCS:%.c=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)

OBJS_BONUS = $(SRC_BONUS:%.c=$(BUILD_DIR)%.o)

#! ******************************************************************************#
#                                    COMMANDS                                    #
#! ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
CC = cc

#! ******************************************************************************#
#                                 FLAGS E COMP                                   #
#! ******************************************************************************#

CFLAGS =  -Wall -Wextra -Werror -g3
DFLAGS =  -g3 -fsanitize=address
LDLIBS = -lft -ldl -lglfw -pthread
LDFLAGS = $(addprefix -L,$(dir $(LIBS)))
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

COMP_BONUS = $(CC) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)

#! ******************************************************************************#
#                                  FUNCTIONS                                     #
#! ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf "$(WHITE) Compiling$(FCOLOR)$(YELLOW) PUSH_SWAP: %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
	@if [ $(COUNT) -eq $(words $(SRCS)) ]; then \
		printf " Compiled $(DARK_GREEN)PUSH_SWAP 100%%$(FCOLOR) ✅"; \
		printf "\n"; \
	fi
endef

define comp_libft
	printf "$(YELLOW)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
	printf "\n"
	printf "$(YELLOW)Building push_swap files$(RESET)\n"
endef

define comp_exe
	$(COMP_EXE)
	printf "\n"
	printf "🌟 $(DARK_BLUE)$(NAME)$(RESET)$(WHITE) is Ready$(RESET) 🌟\n"
endef

define bonus
	$(COMP_BONUS)
endef

define help
	echo "${RED}Available targets:${RESET}"
	printf "\n"
	echo "${DARK_BLUE}re:${RESET}	${LIGHT_GRAY}Rebuild the program${RESET}"
	echo "${DARK_BLUE}all:${RESET}	${LIGHT_GRAY}Build push swap${RESET}"
	echo "${DARK_BLUE}bonus:${RESET}	${LIGHT_GRAY}Build checker${RESET}"
	echo "${DARK_BLUE}clean:${RESET}	${LIGHT_GRAY}Remove the object files${RESET}"
	echo "${DARK_BLUE}fclean:${RESET}	${LIGHT_GRAY}Remove the program and the object files${RESET}"
endef

#! ******************************************************************************#
#                                   TARGETS                                      #
#! ******************************************************************************#

all: $(LIBFT) $(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(LIBFT):
	$(call comp_libft)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

help:
	$(call help)

bonus:  $(LIBFT) $(OBJS_BONUS)
	$(call bonus)

re: fclean all

-include $(DEPS)
