#include "defs.h"
#include "producer.h"
#include "consumer.h"
#include "queue.h"
#include "slot.h"
#include "filegen.h"

#define DEBUG 1

/***
 * test_consume_function - testbed application which runs a single, 
 * unprotected producer, and a single unprotected consumer.
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

    resetallslotbusystates(slotgrp);

    displayslots(slotgrp);

    int j = 0;
    for(j=0;j<NUMBEROFSLOTS;++j)
    {
        slot = requestslot(slotgrp);
        if(slot)
            consume(slot);
    }

    destructqueue(queue);

    exit(0);
}

