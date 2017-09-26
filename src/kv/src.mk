HMAP	:=	kv_delete.c \
			kv_insert.c \
			kv_new.c \
			kv_resize.c \
			kv_search.c

OBJ	:= $(OBJ) $(HMAP:.c=.o)

$(DIROBJ)/%.o: $(DIRHMAP)/%.c $(INC)
	$(COMPIL)
