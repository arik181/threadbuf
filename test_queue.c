#include "defs.h"
#include "queue.h"

/***
 * q - Test framework for FIFO queue
 ***/

int main(int argc, char ** argv)
{
    queueptr thequeue = initqueue();
    char * nameptr;
    char name1[MAXLINESIZE] = "fileone";
    char name2[MAXLINESIZE] = "filetwo";
    char name3[MAXLINESIZE] = "filethree";
    char name4[MAXLINESIZE] = "filefour";
    char name5[MAXLINESIZE] = "filefive";

    nameptr = &name1[0];
    addfile(nameptr, thequeue);

    nameptr = &name2[0];
    addfile(nameptr, thequeue);

    nameptr = &name3[0];
    addfile(nameptr, thequeue);

    nameptr = &name4[0];
    addfile(nameptr, thequeue);

    nameptr = &name5[0];
    addfile(nameptr, thequeue);

    printfiles(thequeue);

    destructqueue(thequeue);

    exit(0);
}

