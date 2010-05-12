#include "defs.h"
#include "filegen.h"

/***
 * filegen - testbed application which creates five files of 
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

int main(int argc, char ** argv)
{
    int filesizes[NUMBEROFFILES];
    char filenames[NUMBEROFFILES][MAXFILENAMESIZE];

    generaterandomvalues(filesizes);
    generatefilenames(filenames);
    generatefiles(filesizes, filenames);

    exit(0);
}

