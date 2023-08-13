END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m
NAME = minishell
FLAGS = -Wall -Werror -Wextra -g3
CC = cc

LIBFTP = libft/
PATHB = build/
PATHO = build/objs/
PATHS = sources/
PATHSL = sources/lexer/
PATHSP = sources/parser/
PATHSB = sources/builtins/
PATHSU = sources/utils/
PATHSE = sources/error/
PATHP = sources/pipex/
PATHEX = sources/executor/

BUILD_PATHS = $(PATHB) $(PATHO)

sources	=	sources/main.c \
		sources/signal.c \
		sources/builtins/builtins.c \
		sources/builtins/m_cd.c \
		sources/builtins/m_echo.c \
		sources/builtins/m_env.c \
		sources/builtins/m_exit.c \
		sources/builtins/m_export.c \
		sources/builtins/m_pwd.c \
		sources/builtins/m_unset.c \
		sources/builtins/utils_builtins.c \
		sources/builtins/p_builtins.c \
		sources/utils/parse_envp.c \
		sources/utils/utils.c \
		sources/error/error_handling.c \
		sources/executor/redirection_check.c \
		sources/executor/executor.c \
		sources/executor/cmds_handler.c \
		sources/executor/exec_utils.c \
		sources/executor/heredoc.c \
		sources/executor/executor_utils.c \
		sources/lexer/input_validation.c \
		sources/lexer/lexer.c \
		sources/lexer/lexer_utils.c \
		sources/lexer/lexer_validation.c \
		sources/lexer/symbol_utils.c \
		sources/lexer/expand_env.c \
		sources/lexer/combine_quotes.c \
		sources/parser/parser.c \
		sources/parser/parser_utils.c \
		sources/parser/redirections.c \
		sources/parser/tokens.c

OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(sources))))

LIBFT	=	./libft/libft.a

HEADER	=	.includes/builtins.h \
			.includes/color.h \
			.includes/error.h \
			.includes/executor.h \
			.includes/minishell.h \
			.includes/parsing.h \
			.includes/lexer.h \
			.includes/utils.h

READLINE_DIR = $(shell brew --prefix readline)

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib -lreadline -L$(LIBFTP) -lft
# READLINE_LIB = -lreadline -lhistory -lreadline -Llibft/ -lft

INCLUDES = -I./includes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include

all: $(BUILD_PATHS) $(NAME)
	@echo "\n${WHITE}${BOLD}${REV}>>>>>>>>>>>>>>>>>>>>>>>>>>>>       ✅ ✅ ✅ ✅ ✅  MANDATORY COMPILATION SUCCESSFULL   🙌 🙌 🙌         <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"
	@echo "\n${WHITE}${BOLD}${REV}>>>>>>>>>>>>>>>>>>>>>>>>>>>>                   BY    SIMON & MARIAM   😎😎😎😎😎😎😎😎                 <<<<<<<<<<<<<<<<<<<<<<<<<<<<${END}"

$(NAME): $(LIBFT) $(OBJS) $(BUILD_PATHS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "${GREEN}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHSP)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c $(HEADERS)
	@echo "${CYAN}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHS)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADERS)
	@echo "${PURPLE}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHSL)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@echo "${YELLOW}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHSB)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@echo "${BLUE}${BOLD}${BLINK}Compiling ${notdir $<}			in	$(PATHSU)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@echo "${WHITE}${BOLD}${BLINK}Compiling ${notdir $<}			in	$(PATHSE)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADERS)
	@echo "${GREY}${BOLD}${UNDER}Compiling ${notdir $<}			in	$(PATHEX)${END}"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFTP)

$(PATHB):
	@mkdir $(PATHB)

$(PATHO):
	@mkdir $(PATHO)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f .tmp*
	@rm -rf $(PATHO) $(PATHB)
	@make fclean -C $(LIBFTP)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o
