#include "defs.h"

int generaterandomvalues(int * filesizes);
int generatefilenames(char filenames[NUMBEROFFILES][MAXFILENAMESIZE]);
int generatefiles(int * filesizes, char filenames[NUMBEROFFILES][MAXFILENAMESIZE]);


int main(int argc, char ** argv)
{
    int filesizes[NUMBEROFFILES];
    char filenames[NUMBEROFFILES][MAXFILENAMESIZE];

    int j;
    for (j=0;j<5;++j)
        strncpy(filenames[j],"\0",1); 


    generaterandomvalues(filesizes);
    generatefilenames(filenames);
    generatefiles(filesizes, filenames);

    exit(0);
}


int generaterandomvalues(int * filesizes)
{
    struct timeval seedtime;
    gettimeofday(&seedtime, NULL);
    srand(seedtime.tv_usec);

    if (filesizes)
    {
        int i;
        for (i=0;i<3;++i)
            filesizes[i] = SMALLFILE;

        for (;i<NUMBEROFFILES;++i)
            filesizes[i] = LARGEFILE;
        return 0;
    }
    else return -1;
}


int generatefilenames(char filenames[NUMBEROFFILES][MAXFILENAMESIZE])
{
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
    FILE * fd;
    int j, k;

    for (j=0;j<NUMBEROFFILES;++j)
    {
        if(fd = fopen(filenames[j],"w"))
        {
            for (k=0;k<filesizes[j];++k)
                fprintf(fd,"a",3);
        }
    }

    int i;
    for (i=0;i<NUMBEROFFILES;++i)
        printf("File %d is named %s, and contains %d characters.\n", \
                i+1, filenames[i], filesizes[i]);
    return 0;
}

