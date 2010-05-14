int produce()
{
           /*** down(mutex2);
            * ++writecount; 
            * if(writecount == 1)
            *   down(readblock);
            * up(mutex2);
            * down(writeblock);
            * access(resource);
            * up(writeblock);
            * down(mutex2);
            * --writecount;
            * if (writecount == 0)
            *   up (readblock);
            * up(mutex2);
            * ***/
    char * array;
//        while(1) 
//        {
//             gets the file name from the FIFO queue
                 fd = requestfile(queue);
//             reads the contents from that file
                 array = readfile(fd);
//             converts all characters to uppercase
                 int i = 0;
                 for(i=0;i<n;++i)
                 {
                     toupper(array[i]);
                 }
//             and writes the contents into any available buffer slot.
                 strncpy(slot, array);
//        }
}

void filetoslot(FILE fd, slotptr writeslot)
{
    char input = '\0';
    if(fopen(fd))
    {
        read(fd, input);
        writetoslot(writeslot, input);
    }
}

void writetoslot(char inputchar, slotptr writeslot)
{
    int i = 0;
    for(i=0;i<SIZEOFSLOT;++i)
    {
        if(writeslot)
        {
            writeslot -> content[i] = inputchar;
        }
    }
}

