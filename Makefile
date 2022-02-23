##############################################################################
# Macros
##############################################################################

# Compiler macros
CC = gcc -m32
CCFLAGS = -o $(OBJDIR)/$@ -Wall -c $<

# NOTE: Object targets go here!
OBJ = gm_vector.o gm_matrix.o gm_misc.o
OBJDIR = .
OBJPATH = $(addprefix $(OBJDIR)/, $(OBJ))
	
##############################################################################
# Build targets
##############################################################################

default: libgmath clean-obj

# Build libraries
libgmath: CC += -O2
libgmath: $(OBJ)
	ar rcs $@.a $(OBJPATH)


##############################################################################
# Object targets
##############################################################################

gm_vector.o: src/gmath/gm_vector.c src/gmath/gmath.h
	$(CC) $(CCFLAGS)
gm_matrix.o: src/gmath/gm_matrix.c src/gmath/gmath.h
	$(CC) $(CCFLAGS)
gm_misc.o: src/gmath/gm_misc.c src/gmath/gmath.h
	$(CC) $(CCFLAGS)

##############################################################################
# Phony targets
##############################################################################

.PHONY: clean clean-obj

clean:
	rm -f $(OBJDIR)/*.o libgmath.a
clean-obj:
	rm -f $(OBJDIR)/*.o
