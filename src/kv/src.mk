HMAP	:=	kvs_delete.c \
			kvs_extract.c \
			kvs_insert.c \
			kvs_new.c \
			kvs_resize.c \
			kvs_search.c \
			kvs_to_str.c

OBJ	:= $(OBJ) $(HMAP:.c=.o)

$(DIROBJ)/%.o: $(DIRHMAP)/%.c $(INC)
	$(COMPIL)
