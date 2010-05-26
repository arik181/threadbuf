#include <stdio.h>

#include "producer.h"
#include "slot.h"
#include "queue.h"


int produce(packageptr thepackage)
{
    FILE * inputfile;
    char inputchar;

    char * filename;
    char * slot;

    sem_t * fifomutex = &(thepackage -> thequeue -> fifomutex);
    sem_t * emptysem = &(thepackage -> thebuffer -> emptysemaphore);
    sem_t * fullsem = &(thepackage -> thebuffer -> fullsemaphore);
    slotgroupptr thebuffer = thepackage -> thebuffer;
    queueptr thequeue = thepackage -> thequeue;

    while(thequeue -> count > 0)
    {


        if(thepackage)
        {
            int semvalue = 0;
            int * valptr = &semvalue;
            sem_wait(emptysem);
            sem_getvalue(emptysem,valptr);

            // Get the next available buffer slot 
            slot = requestslot(thebuffer, semvalue);

            int j;
            for (j=0;j < SIZEOFSLOT;++j)
            {
                slot[j] = '\0';
            }

            // Get the name of the next file
            sem_wait(fifomutex);
            filename = getfile(thequeue);
            sem_post(fifomutex);

            // reads the contents from a file
            if(inputfile = fopen(filename, "r"))
            {
                int i = 0;
                while (i < SIZEOFSLOT)
                {
                   //  converts all characters to uppercase
                   //  and writes the contents into the 
                   //  given buffer slot.
                   inputchar = fgetc(inputfile);
                   if (inputchar >= 'a' && inputchar <= 'z')
                       slot[i] = UPPERCASE(inputchar);
                   ++i;
                   if (inputchar == EOF)
                       break;
                }
                if(i < SIZEOFSLOT)
                    slot[i+1] = '\0';

            }
            printf("%s\n", slot);

            int k;
            for (k=0;k < SIZEOFSLOT;++k)
            {
                slot[k] = '\0';
            }

            sem_post(fullsem);
        }
        else return -1;

    }

}
