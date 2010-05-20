#include "filegen.h"

int generaterandomvalues(int * filesizes)
{
    struct timeval seedtime;
    gettimeofday(&seedtime, NULL);
    srand(seedtime.tv_usec);

    if (filesizes)
    {
        int i;
        for (i=0;i<NUMBEROFSMALLFILES;++i)
            filesizes[i] = SMALLFILE;

        for (;i<NUMBEROFFILES;++i)
            filesizes[i] = LARGEFILE;
        return 0;
    }
    else return -1;
}


int generatefilenames(char filenames[NUMBEROFFILES][MAXFILENAMESIZE])
{
    int j;
    for (j=0;j<NUMBEROFFILES;++j)
        strncpy(filenames[j],"\0",1); 

    int i;
    for (i=0;i<NUMBEROFFILES;++i)
    {
        if (filenames)
        {
            sprintf(filenames[i],"in%d.txt\0",i);
        }
        else return -1;
    }
}


int generatefiles(int * filesizes, char filenames[NUMBEROFFILES][MAXFILENAMESIZE])
{
    FILE * file;
    int j,k;
    char character = 'a';

    for (j=0;j<NUMBEROFFILES;++j,++character)
    {
        if(file = fopen(filenames[j],"w"))
        {
            for (k=0;k<filesizes[j];++k)
                fprintf(file,"%c",character);
            fclose(file);
        }
    }

    int i;
    for (i=0;i<NUMBEROFFILES;++i)
        printf("File %d is named %s, and contains %d characters.\n", \
                i+1, filenames[i], filesizes[i]);
    return 0;
}

