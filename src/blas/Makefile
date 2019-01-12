# Compilation
# compiler (if defined use 'cc' else use clang)
CC ?= gcc

# compilation flags
CFLAGS = -pedantic# warn on language extensions
CFLAGS += -std=c11# C11 standard mode
CFLAGS += -Werror# turn warnings into errors.
CFLAGS += -Wall#turn on all warnings
CFLAGS += -Wextra# turn on extra warnings
# libraries flags
LIBS = -lm
# optimization flags
OPT_FLAGS = -O2# optimization level
OPT_FLAGS += -ffast-math# fast math mode

#Utilities
MKDIR = /bin/mkdir -p
RM = /bin/rm -f

# Files
SRCS = $(wildcard ./*.c)
OBJS = $(SRCS:%.c=%.o)

#Rules
all: CFLAGS += $(OPT_FLAGS)
all: $(OBJS)

%.o: %.c blas.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) -r $(OBJS)

