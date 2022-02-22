##############################################################################
# Macros
##############################################################################

# Compiler macros
CC = gcc -m32
CCFLAGS = -o $(OBJDIR)/$@ -Wall -c $<

# File macros
TARGET = bin/out
# NOTE: Object targets go here!
OBJ = gm_vector.o gm_matrix.o gm_misc.o
OBJDIR = bin
OBJPATH = $(addprefix $(OBJDIR)/, $(OBJ))
	
##############################################################################
# Build targets
##############################################################################

default: libgmath release

# Build debug
debug: CC += -g -DDEBUG
debug: $(OBJ) exec

# Build release
release: CC += -O2
release: $(OBJ) src/main.c
	$(CC) -I./ext -L./ext/lib -o bin/release src/main.c -lgmath

# Build executables
exec: src/main.c
	$(CC) -o $(TARGET) $< $(OBJPATH);

# Build libraries
libgmath: CC += -O2
libgmath: $(OBJ)
	ar rcs ext/lib/$@.a $(OBJPATH)


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
	rm -f $(OBJDIR)/*.o $(TARGET)
clean-obj:
	rm -f $(OBJDIR)/*.o
