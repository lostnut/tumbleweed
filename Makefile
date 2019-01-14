################################################################################
############################# General ##########################################
################################################################################
all: dryrun blas test-blas doc

clean: clean-dryrun clean-blas clean-doc
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
############################# TeX ##############################################
################################################################################
# latex compiler
LC = latexmk
# latex compiler flags
LFLAGS = -pdf
LFLAGS += -interaction=nonstopmode
################################################################################
############################# Dryrun ###########################################
################################################################################
# compilation flags
DRYRUN_FLAGS = $(CFLAGS)
DRYRUN_FLAGS += -O2
DRYRUN_FLAGS += -ffast-math
# path
DRYRUN_PATH = src/dryrun
# files
DRYRUN_SRC = $(wildcard $(DRYRUN_PATH)/*.c)
DRYRUN_INC = $(wildcard $(DRYRUN_PATH)/*.h)
DRYRUN_OBJ = $(DRYRUN_SRC:%.c=%.o)
# phony
.PHONY: dryrun clean-dryrun
# rules
dryrun: $(DRYRUN_INC) $(DRYRUN_OBJ)

$(PATH_DRYRUN)/%.o: %.c $(DRYRUN_INC)
	$(CC) $(DRYRUN_FLAGS) -c $< -o $@

clean-dryrun:
	$(RM) $(DRYRUN_OBJ)
################################################################################
############################# BLAS #############################################
################################################################################
# compilation flags
BLAS_FLAGS = $(CFLAGS)
BLAS_FLAGS += -O2
BLAS_FLAGS += -ffast-math
# compilation flags test
BLAS_FLAGS_TEST = $(CFLAGS)
BLAS_FLAGS_TEST += -O0
# path
BLAS_PATH= src/blas
BLAS_PATH_TEST = test/blas
# test includes
BLAS_TEST_INCLUDES = -I$(BLAS_PATH)
BLAS_TEST_INCLUDES += -I$(DRYRUN_PATH)
# files
BLAS_SRC = $(wildcard $(BLAS_PATH)/*.c)
BLAS_OBJ = $(BLAS_SRC:%.c=%.o)
BLAS_HEADER = $(BLAS_PATH)/blas.h
BLAS_TST = $(wildcard $(BLAS_PATH_TEST)/*.c)
BLAS_TST_EXEC = $(BLAS_PATH_TEST)/test-blas.a
# phony
.PHONY: blas test-blas blas-compile-test blas-run-test
#rules
blas: $(BLAS_HEADER) $(BLAS_OBJ)

$(PATH_BLAS)/%.o: %.c $(BLAS_HEADER)
	$(CC) $(BLAS_FLAGS) -c $< -o $@

test-blas: blas blas-compile-test blas-run-test

blas-compile-test: $(BLAS_SRC) $(BLAS_TST) $(DRYRUN_OBJ)
	$(CC) $(BLAS_FLAGS_TEST) $(BLAS_TEST_INCLUDES) $^ -o $(BLAS_TST_EXEC)

blas-run-test:
	$(BLAS_TST_EXEC)

.PHONY: clean-blas clean-blas-src clean-blas-test
clean-blas: clean-blas-src clean-blas-test

clean-blas-src:
	$(RM) $(BLAS_OBJ)

clean-blas-test:
	$(RM) $(BLAS_TST_EXEC)
################################################################################
############################# Documentation ####################################
################################################################################
# path
DOC_PATH = doc
# main doc file
DOC_MAIN = main.tex
# doc files 
DOC_OBJ = main.aux\
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
	$(CD) $(DOC_PATH); \
	$(LC) $(LFLAGS) $(DOC_MAIN)

clean-doc:
	$(CD) $(DOC_PATH); \
	$(RM) $(DOC_OBJ)

