#include "producer.h"
#include "slot.h"
#include "queue.h"

void * initproducer(queueptr thequeue, sem_t * fifomutex)
{
    producerptr theproducer = calloc(1,sizeof(struct producer));

    if (theproducer)
    {
        while(1)
        {
            sem_wait(fifomutex);
            theproducer -> filename = getfile(thequeue);
            sem_post(fifomutex);

            produce(theproducer);
        }
    }

    return theproducer;
}

void setfilename(char * filename)
{
}

void setslot(char * slot)
{
}

int produce(producerptr producer)
{
    FILE * inputfile;
    char inputchar;
    
    if(producer && producer -> slot && producer -> filename)
    {
        char * slot = producer -> slot;
        char * filename = producer -> filename;

        int j;
        for (j=0;j < SIZEOFSLOT;++j)
        {
            slot[j] = '\0';
        }

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
    }
    else return 0;
}

