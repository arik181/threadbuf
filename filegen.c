#include "defs.h"

/***
 * filegen - utility application which creates five files of 
 * pseudorandom size, containing characters from a-e, depending
 * on the file. Files are named "in1.txt", "in2.txt" ... "in4.txt", 
 * and contain the characters 'a' - 't', respectively.
 *
 * For the five generated files, if A is the size of the document in
 * characters, then:
 *
 *  "in1.txt"  - "in12.txt" => {   0 < A < 129 } 
 *  "in13.txt" - "in20.txt" => { 128 < A < 256 } 
 *
 ***/

int generaterandomvalues(int * filesizes);
int generatefilenames(char filenames[NUMBEROFFILES][MAXFILENAMESIZE]);
int generatefiles(int * filesizes, char filenames[NUMBEROFFILES][MAXFILENAMESIZE]);

int main(int argc, char ** argv)
{
    int filesizes[NUMBEROFFILES];
    char filenames[NUMBEROFFILES][MAXFILENAMESIZE];

    int j;
    for (j=0;j<NUMBEROFFILES;++j)
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
    int j,k;
    char character = 'a';

    for (j=0;j<NUMBEROFFILES;++j,++character)
    {
        if(fd = fopen(filenames[j],"w"))
        {
            for (k=0;k<filesizes[j];++k)
                fprintf(fd,"%c",character);
        }
    }

    int i;
    for (i=0;i<NUMBEROFFILES;++i)
        printf("File %d is named %s, and contains %d characters.\n", \
                i+1, filenames[i], filesizes[i]);
    return 0;
}

