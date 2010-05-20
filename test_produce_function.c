#include "defs.h"
#include "producer.h"
#include "queue.h"
#include "slot.h"
#include "filegen.h"

#define DEBUG 1

/***
 * test_produce_function - testbed application which runs a single, 
 * unprotected producer.
 ***/

int main(int argc, char ** argv)
{
    queueptr queue;
    slotgroupptr slotgrp;
    char * slot = NULL;
    char * filename;
    int filesizes[NUMBEROFFILES];
    char filenames[NUMBEROFFILES][MAXFILENAMESIZE];

    queue = initqueue();
    int i = 0;

    if (DEBUG)
    {
        generaterandomvalues(filesizes);
        generatefilenames(filenames);
        generatefiles(filesizes, filenames);

        for(i=0;i<NUMBEROFFILES;++i)
        {
            addfile(filenames[i], queue);
        }
    }

    slotgrp = initslots();
    do 
    {
        filename = getfile(queue);
        slot = requestslot(slotgrp);
        if(filename && slot)
            produce(filename, slot);
    } while (filename && slot);

    displayslots(slotgrp);
    destructqueue(queue);

    exit(0);
}

