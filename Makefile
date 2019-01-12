################################################################################
############################# Utilities ########################################
################################################################################
CD = cd
PWD = pwd
RM = rm -f
MKDIR = mkdir -p
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

