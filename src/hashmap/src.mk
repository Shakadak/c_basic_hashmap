HMAP	:=	hashmap_delete.c \
			hashmap_insert.c \
			hashmap_new.c \
			hashmap_search.c

OBJ	:= $(OBJ) $(HMAP:.c=.o)

$(DIROBJ)/%.o: $(DIRHMAP)/%.c $(INC)
	$(COMPIL)
