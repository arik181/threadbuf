#include "defs.h"
#include "queue.h"
#include "filegen.h"

/***
 * test_file_queue_integration - testbed application which creates five 
 * files of pseudorandom size, (see test_filegen for more details...), and
 * places these files into a FIFO queue. See (test_queue for more details
 * on the queue implementation...)
 ***/

int main(int argc, char ** argv)
{
    queueptr thequeue = initqueue();

    int filesizes[NUMBEROFFILES];
    char filenames[NUMBEROFFILES][MAXFILENAMESIZE];

    generaterandomvalues(filesizes);
    generatefilenames(filenames);
    generatefiles(filesizes, filenames);

    int i;
    for (i=0;i<NUMBEROFFILES;++i)
        addfile(filenames[i], thequeue);

    printfiles(thequeue);

    destructqueue(thequeue);

    exit(0);
}

