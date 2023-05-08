# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbouma <jbouma@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 14:09:40 by jbouma        #+#    #+#                  #
#    Updated: 2023/05/01 21:56:25 by jensbouma     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Program Name(s)
NAME		=	push_swap

# Compiler Settings
CC 			:= gcc
CFLAGS 		:=
# -Wall -Wextra -Werror
# CFLAGS		:= -Wall -Wextra -Werror -g -fsanitize=address

# Headers
INC 		= -I include

# Set build directories
BUILDDIR	= ./build/
TARGET		= bin/$<

# Sources
SRCDIR		= 	src
FILES		= 	main.c			\
				error.c			\
				smarttools.c	\
				list.c			\
				# swap.c			\
				push.c			\

SOURCES		=	${addprefix $(SRCDIR)/, $(FILES)}

# Libraries
LIBDIR		=	lib

LIBS		=	LibFT

HEADERS		=	$(LIBS:%=-I $(LIBDIR)/%/include)

LIBARIES		=	${addprefix $(LIBDIR)/, $(LIBS)}
LIBARIES_AFILES	=	${addprefix $(BUILDDIR)/, ${addsuffix .a, $(LIBS)}}

# Objects
OBJECTS		= $(SOURCES:%.c=$(BUILDDIR)%.o)

# Colors
ifneq (,$(findstring xterm,${TERM}))
	BLACK		:= $(shell tput -Txterm setaf 0)
	RED			:= $(shell tput -Txterm setaf 1)
	GREEN		:= $(shell tput -Txterm setaf 2)
	YELLOW		:= $(shell tput -Txterm setaf 3)
	LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
	PURPLE		:= $(shell tput -Txterm setaf 5)
	BLUE		:= $(shell tput -Txterm setaf 6)
	WHITE		:= $(shell tput -Txterm setaf 7)
	RESET		:= $(shell tput -Txterm sgr0)
endif

P_OK			= printf "$@ \t\t%s\033[0K\n" "${GREEN}Norm OK${RESET}"
P_KO			= printf "$@ \t\t%s\033[0K\n" "${RED}Norm KO${RESET}"
P_NL			= printf " \n"

# Rules
all: $(NAME)
	@mkdir -p ./bin
	@$(CC) $(CFLAGS) $(HEADERS) $(INC) $(OBJECTS) $(LIBARIES_AFILES) -o $(TARGET)
	@printf "Executable \t$< \033[0K\n"

	@printf "\n🙏 $(GREEN)Complete $(RESET)\t\033[0K\n"

$(BUILDDIR)%.o:%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 
	@norminette -R CheckForbiddenSourceHeader $< > /dev/null && printf "Build \t\t${GREEN}$(notdir $<) \033[0K\r\n" ||  printf "Build \t\t${RED}$(notdir $<) \033[0K\r\n"
	@printf "${RESET}"

$(LIBS):
	@printf "Submodule \t$@ \033[0K\r\n"
	@git submodule update --init
	@norminette -R CheckForbiddenSourceHeader $(LIBDIR)/$@/include $(LIBDIR)/$@/src > /dev/null && $(P_OK) || { $(P_KO); }
	@make -C $(LIBDIR)/$@
	@cp -p $(LIBDIR)/$@/$@.a $(BUILDDIR)

$(NAME): $(OBJECTS) $(LIBS)
	@make norminette 2> /dev/null && $(P_OK) || { $(P_KO);}
	

clean:
	@rm -rf build
	@rm -rf $(LIBDIR)/*/*.a

fclean: clean
	@rm -rf $(LIBDIR)/*/build
	@rm -rf bin

re: fclean all

norm: $(SOURCES)
	@norminette -R CheckForbiddenSourceHeader $^ includes > /dev/null && exit 0 || exit 1

.PHONY: all clean fclean re
