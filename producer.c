#include "producer.h"
#include "slot.h"
#include "queue.h"

producerptr initproducer(char * filename)
{
    while(1)
    {
        produce(filename, slot) 
    }

}

int produce(char * filename, char * slot)
{
    FILE * inputfile;
    char inputchar;
    
    if(slot)
    {
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

