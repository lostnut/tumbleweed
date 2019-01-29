################################################################################
############################# General ##########################################
################################################################################
# phony
.PHONY: all clean compile test
#rules
all: softtest blas test-blas doc

compile: softtest blas

test: test-blas

clean: clean-softtest clean-blas clean-doc
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
############################# Softtest #########################################
################################################################################
# compilation flags
SOFTTEST_FLAGS = $(CFLAGS)
SOFTTEST_FLAGS += -O2
# compilation flags test
SOFTTEST_FLAGS_TEST = $(CFLAGS)
SOFTTEST_FLAGS_TEST += -O0
# path
SOFTTEST_PATH = src/softtest
SOFTTEST_PATH_TEST = test/softtest
# test includes
SOFTTEST_TEST_INCLUDES = -I$(SOFTTEST_PATH)
# files
SOFTTEST_SRC = $(wildcard $(SOFTTEST_PATH)/*.c)
SOFTTEST_INC = $(wildcard $(SOFTTEST_PATH)/*.h)
SOFTTEST_OBJ = $(SOFTTEST_SRC:%.c=%.o)
SOFTTEST_TST = $(wildcard $(SOFTTEST_PATH_TEST)/*.c)
SOFTTEST_TST_EXEC = $(SOFTTEST_PATH_TEST)/test-softtest.a
# phony
.PHONY: softtest clean-softtest test-softtest softtest-compile-test softtest-run-test
# rules
softtest: $(SOFTTEST_INC) $(SOFTTEST_OBJ)

$(PATH_SOFTTEST)/%.o: %.c $(SOFTTEST_INC)
	$(CC) $(SOFTTEST_FLAGS) -c $< -o $@

test-softtest: softtest softtest-compile-test softtest-run-test

softtest-compile-test: $(SOFTTEST_SRC) $(SOFTTEST_TST) $(SOFTTEST_OBJ)
	$(CC) $(SOFTTEST_FLAGS_TEST) $(SOFTTEST_TEST_INCLUDES) $^ -o $(SOFTTEST_TST_EXEC)

softtest-run-test:
	$(SOFTTEST_TST_EXEC)

clean-softtest:
	$(RM) $(SOFTTEST_OBJ)
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
BLAS_TEST_INCLUDES += -I$(SOFTTEST_PATH)
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

blas-compile-test: $(BLAS_SRC) $(BLAS_TST) $(SOFTTEST_OBJ)
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

