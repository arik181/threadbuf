#include <string.h>
#include "util.h"

/*** Remove trailing newline from a string ***/
int chomp(char * chompstring, char tail)
{
    if (!chompstring)
        return -1;

    int lastchar = strlen(chompstring) - 1;

    if (chompstring[lastchar] == tail)
    {
        chompstring[lastchar] = '\0';
        return 1;
    }
    else 
        return 0;
}

/*** Remove trailing whitespace from a string ***/
int chompwhitespace(char * chompstring)
{

    if (!chompstring)
        return -1;

    int foundwhitespace = 0;
    int lastchar = strlen(chompstring) - 1;

        
    
    while (chompstring[lastchar] == '\t' || 
           chompstring[lastchar] == '\n' || 
           chompstring[lastchar] == ' ')
    {
        foundwhitespace = 1;
        chompstring[lastchar] = '\0';
        lastchar = strlen(chompstring) - 1;

    }

    if (foundwhitespace)
        return 1;
    else 
        return 0;
}

