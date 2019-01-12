################################################################################
############################# General ##########################################
################################################################################
PATH_TEST=test
TST = $(wildcard $(PATH_TEST)/*.c)
################################################################################
############################# Utilities ########################################
################################################################################
CD = cd
PWD = pwd
RM = rm -f
MKDIR = mkdir -p
################################################################################
############################# C ################################################
################################################################################
# C compiler
CC ?= gcc
# compilation flags
CFLAGS = -pedantic# warn on language extensions
CFLAGS += -std=c11# C11 standard mode
CFLAGS += -Werror# turn warnings into errors.
CFLAGS += -Wall#turn on all warnings
CFLAGS += -Wextra# turn on extra warnings
################################################################################
############################# BLAS #############################################
################################################################################
# compilation flags
BLAS_FLAGS = CFLAGS
BLAS_FLAGS += -O2
BLAS_FLAGS += -ffast-math
# compilation flags test
BLAS_FLAGS_TEST = CFLAGS
BLAS_FLAGS_TEST = -O0
# test includes
BLAS_TEST_INCLUDES = -I$(PATH_BLAS)
BLAS_TEST_INCLUDES += -I$(PATH_TEST)
# path
PATH_BLAS = src/blas
PATH_BLAS_TEST = test/blas
# files
BLAS_SRC = $(wildcard $(PATH_BLAS)/*.c)
BLAS_OBJ = $(BLAS_SRC:%.c=%.o)
BLAS_HEADER = $(PATH_BLAS)/blas.h
BLAS_TST = $(wildcard $(PATH_BLAS_TEST)/*.c)
BLAS_TST_EXEC = $(PATH_BLAS_TEST)/test-blas.a
# phony
.PHONY: blas test-blas blas-compile-test blas-run-test
#rules
blas: $(BLAS_HEADER) $(BLAS_OBJ)

$(PATH_BLAS)/%.o: %.c $(BLAS_HEADER)
	$(CC) $(BLAS_FLAGS) -c $< -o $@

test-blas: blas blas-compile-test blas-run-test

blas-compile-test: $(BLAS_SRC) $(BLAS_TST) $(TST)
	$(CC) $(BLAS_FLAGS_TEST) $(BLAS_TEST_INCLUDES) $^ -o $(BLAS_TST_EXEC)

blas-run-test:
	$(BLAS_TST_EXEC)

clean-blas: 
	$(RM) $(BLAS_OBJ)

################################################################################
############################# Documentation ####################################
################################################################################
# latex compiler 
LC = latexmk
# latex compiler flags
LFLAGS = -pdf
LFLAGS += -interaction=nonstopmode
# path
PATH_DOC = doc
# main tex file
TEX_MAIN = main.tex
# doc files 
TEX_FILES = main.aux\
	    main.fdb_latexmk\
	    main.fls\
	    main.log\
	    main.out\
	    main.pdf\
	    main.toc
# phony
.PHONY: doc
# rules 
doc:
	$(CD) $(PATH_DOC); \
	$(LC) $(LFLAGS) $(TEX_MAIN)

clean-doc:
	$(CD) $(PATH_DOC); \
	$(RM) $(TEX_FILES)

