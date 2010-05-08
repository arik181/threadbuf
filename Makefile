# Change Me
NAME1	= threadbuf
NAME2	= filegen
ADIR	= arik182

# Constant Variables
CC	= gcc
AS	= as
LD	= ld

# Files
#SRC	= defs.h filegen.c main.h main.c util.c
SRC2	= defs.h filegen.c 
TEXSRC = designdoc.tex 
PDFFILES = designdoc.pdf 

# Flags
NC			= -lncurses
DEBUG		= -g
OPT			= -O2
OBJECT		= -c
PROFILE		= -pg
CFLAGS		= $(DEBUG) 
LDFLAGS		= -lc -dynamic-linker /lib/ld-linux.so.2

### Compile the application ###

all : debug2

debug1 : $(SRC)
	$(CC) $(CFLAGS) $(SRC1) -o $(NAME1)
	ctags $(SRC1)
	gdb ./$(NAME1)

debug2 : $(SRC)
	$(CC) $(CFLAGS) $(SRC2) -o $(NAME2) 
	ctags $(SRC2)
	gdb ./$(NAME2)

$(NAME1) : $(SRC)
	$(CC) $(CFLAGS) -o $(NAME1) $(SRC)

$(NAME2) : $(SRC)
	$(CC) $(CFLAGS) -o $(NAME2) $(SRC)

### Special Cases ###

clean : 
	rm -rf $(NAME1) 
	rm -rf $(NAME2) 
	rm -rf *.o 
	rm -rf in*.txt

homework : $(NAME1) $(NAME2) $(SRC) typescript
	echo "Cleaning up..."
	rm -rf $(ADIR)
	echo "Creating directory..."
	mkdir $(ADIR)
	echo "Copying targets..."
	cp Makefile $(SRC) typescript $(ADIR)/
	tar cvf $(ADIR).tar $(ADIR)
	echo "Done."

UNAME		= arik181
TITLE		= CS333 Project 1
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

