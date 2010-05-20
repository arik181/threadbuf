# Change Me
NAME	= prod_com
ADIR	= arik182

# Constant Variables
CC	= gcc
AS	= as
LD	= ld

# Files
FILEGENSRC  = defs.h test_filegen.c filegen.c filegen.h
#SRC		= defs.h main.h main.c queue.h queue.c util.c filegen.c filegen.h
SRC		= defs.h slot.h producer.h queue.h filegen.h filegen.c test_consume_function.c consumer.h consumer.c slot.c producer.c queue.c
#SRC = test_pthreads.c

TEXSRC = designdoc.tex 
PDFFILES = designdoc.pdf 

# Flags
#LIB		= -lncurses
#LIB			= -lpthread # -lrt
DEBUG		= -g
OPT			= -O2
OBJECT		= -c
PROFILE		= -pg
CFLAGS		= $(DEBUG) 

### Compile the application ###

all : debug

debug : $(SRC)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $?
	ctags $?
	gdb ./$(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(LIB) -o $@ $?

filegen : $(FILEGENSRC)
	$(CC) $(CFLAGS) -o $@ $?

### Special Cases ###

clean : 
	rm -rf $(NAME) 
	rm -rf *.o 
	rm -rf in*.txt

homework : $(NAME) $(SRC) typescript
	echo "Cleaning up..."
	rm -rf $(ADIR)
	echo "Creating directory..."
	mkdir $(ADIR)
	echo "Copying targets..."
	cp Makefile $(SRC) typescript $(ADIR)/
	tar cvf $(ADIR).tar $(ADIR)
	echo "Done."

UNAME		= arik181
TITLE		= CS333 Project 2
ADDRESS1	= cs333acc@cs.pdx.edu
ADDRESS2	= $(UNAME)@gmail.com
DIR			= $(UNAME)/
TARFILE		= $(UNAME).tar.gz

tar : homework	
	rm -rf $(TARFILE)
	tar czvf $(TARFILE) $(DIR)

mail : tar 
	mpack -a -s '$(TITLE) tar archive' $(TARFILE) $(ADDRESS1)
	mpack -a -s '$(TITLE) tar archive' $(TARFILE) $(ADDRESS2)

tex : $(TEXSRC)
	pdflatex $(TEXSRC)
	cp -f $(PDFFILES) ~/public_html/

