################################################################################
############################# General ##########################################
################################################################################
# phony
.PHONY: all clean compile test
#rules
all: softtest doc

compile: softtest

test: 

clean: clean-softtest clean-doc
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

