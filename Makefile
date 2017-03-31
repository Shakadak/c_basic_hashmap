# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2015/05/21 20:34:00 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	liblphm.a

### DIRECTORIES ###

DIRSRC		:=	src
DIROBJ		:=	obj
DIRTST		:=	test
DIRLIB		:=	lib
DIRBIN		:=	bin
DIRMEM		:=	$(DIRSRC)/mem
DIRDHM		:=	$(DIRSRC)/hashmap
DIRINC		:=	inc

### FILES ###

### FILES: SOURCES ###

include $(DIRMEM)/src.mk
include $(DIRHM)/src.mk

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))

### ARCHIVE ###

AR			:=	ar
AR_FLAG		:=	-crus
AR_EXEC		=	$(AR) $(AR_FLAG) $@ $^

### COMPILATION ###

CC			:=	clang
C_FLAG		:=	-Wall -Wextra -Werror
I_FLAG		:=	-I $(DIRINC) -I .
O_FLAG		:=	-O3
C_OPT		=	-o $@ -c $< $(I_FLAG)
COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)
L_FLAG		:= -L $(DIRLIB) -lmds

### RULES ###

all: $(DIRLIB)/$(NAME)

test: $(DIRLIB)/$(NAME)
	$(CC) $(C_FLAG) $(I_FLAG) $(L_FLAG) -o $(DIRTST)/test.tst $(DIRTST)/darray_test.c
	./$(DIRTST)/test.tst
	

### RULES: ARCHIVE ###

$(DIRLIB)/$(NAME): $(POBJ) |$(DIRLIB)
	$(AR_EXEC)
	ranlib $@

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(DIRLIB):
	mkdir $(DIRLIB)

clean:
	rm -f $(POBJ)

fclean: clean
	rm -f $(DIRLIB)/$(NAME)
	rm -f $(DIRTST)/test.tst

re: fclean all

.PHONY: all test clean re fclean
