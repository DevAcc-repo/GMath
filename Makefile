##############################################################################
# Macros
##############################################################################

# Compiler macros
CC = gcc
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

gm_vector.o: src/gm_vector.c include/gmath.h
	$(CC) $(CCFLAGS)
gm_matrix.o: src/gm_matrix.c include/gmath.h
	$(CC) $(CCFLAGS)
gm_misc.o: src/gm_misc.c include/gmath.h
	$(CC) $(CCFLAGS)

##############################################################################
# Phony targets
##############################################################################

.PHONY: clean clean-obj

clean:
	rm -f $(OBJDIR)/*.o libgmath.a
clean-obj:
	rm -f $(OBJDIR)/*.o
