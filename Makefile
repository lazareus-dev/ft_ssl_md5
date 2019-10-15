# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/10 10:53:13 by tle-coza     #+#   ##    ##    #+#        #
#    Updated: 2019/10/15 13:31:48 by tle-coza    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        =   ft_ssl

CC = clang

FLAGS		= 	-Wall -Wextra -Werror -O2 -g

SSL_MD5		=	$(addprefix ssl_md5/, \
				ssl_md5.c md5_aux_fcts.c md5_transformation_fcts.c md5_final.c \
				md5_transform.c md5_apply_transformation.c md5_update.c \
				md5_init.c)

SSL_SHA256		=	$(addprefix ssl_sha256/, \
				ssl_sha256.c)

FILENAMES   =   main.c ssl_hashing.c ssl_usage.c ssl_process.c ssl_arg.c \
				debug.c \
				$(SSL_MD5) \
				$(SSL_SHA256) \

SOURCES     =   $(addprefix srcs/, $(FILENAMES))

OBJECTS     =   $(SOURCES:.c=.o)

L_FT        =   ./libft

LIB_LNK     =   -L $(L_FT) -l ft

LIB_INC     =   -I $(L_FT)/libft.h

.PHONY: all clean fclean re

all: $(NAME)

lib: 
		@if (make -q -C $(L_FT)); then \
			echo "\033[0;35mlibft.a: Ready to go ️🏎️ \033[0m";\
		fi;
		@if !(make -q -C $(L_FT)); then \
			echo "\033[0;96mlibft.a: Compiling ⏳️\033[0m"; \
			make -C $(L_FT); \
		fi;

$(NAME): $(OBJECTS) #lib
		@echo "\033[0;96m$(NAME): Compiling ⏳️\033[0m"
		@$(CC) -I ./includes $(OBJECTS) $(TERMCAP_LNK) $(LIB_LNK) -o $@
		@echo "\033[1;34m~ Welcome to LazySH ~\033[0m"

%.o: ./%.c
	    @$(CC) $(FLAGS) $(LIB_INC) -I ./includes -c $< -o $@

clean:
		#@$(MAKE) -C $(L_FT) clean
		@rm -rf $(OBJECTS)
		@echo "\033[0;32m$(NAME): Spotless ✨\033[0m"

fclean: clean
		@rm -rf $(NAME)
		#@$(MAKE) -C $(L_FT) fclean

clear:
		@$(MAKE) all
		@$(MAKE) clean

re:
	    @$(MAKE) fclean
		@$(MAKE) all
