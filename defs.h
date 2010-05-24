#ifndef DEFS
#define DEFS

/*** Includes ***/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

/*** Integer Definitions ***/

/*** File Related ***/
#define NUMBEROFSMALLFILES  12
#define NUMBEROFFILES       20
#define SMALLMAXFILELENGTH  127
#define SMALLMINFILELENGTH  1
#define LARGEMAXFILELENGTH  128
#define LARGEMINFILELENGTH  128
#define SMALLFILE (rand() % SMALLMAXFILELENGTH) + SMALLMINFILELENGTH;
#define LARGEFILE (rand() % LARGEMAXFILELENGTH) + LARGEMINFILELENGTH;
#define MAXFILENAMESIZE     128

/*** Semaphore Related ***/
#define INITIALSEMVALUE     0

/*** Thread related ***/
#define MAXPRODUCERS        20
#define MAXCONSUMERS        5

/*** Buffer Related ***/
#define NUMBEROFSLOTS       5
#define SIZEOFSLOT          129
#define FORMATSTRINGSIZE    30
#define BYTESIZE            8
#define CHARSIZE            1
#define BUFSIZE             1
#define MAXLINESIZE         1024
#define MAXARGS             64
#define MAXCMDS             2
#define ARGNAME             1
#define NAMEPLUSFLAG        2
#define CHARSINARG          2
#define HISTORYSIZE         100
#define NUMLOCATION         1
#define UPPERCASE(x)        x-32

/*** Flags ***/
#define TRUE            0x1
#define FALSE           0x0
#define SYM_LT          0x1
#define SYM_LT_APPEND   0x2
#define SYM_GT          0x4
#define SYM_GT_APPEND   0x8
#define SYM_PIPE        0x10

#define DEFAULT         0x0
#define QUIT            0x8
#define BUILTIN         0x4
#define BACKGROUND      0x2
#define HISTERROR       0x1
#define REDIRECTION     0x10
#define PIPE            0x20

/*** Flag Related Macros ***/
#define IS(X,Y)         (X & Y)
#define BUILTIN_ON *stateptr |= BUILTIN;
#define HISTERROR_ON *stateptr |= HISTERROR;
#define TURN_BACKGROUND_ON *stateptr |= BACKGROUND;
#define TURN_REDIRECTION_ON *stateptr |= REDIRECTION;
#define TURN_PIPE_ON *stateptr |= PIPE;

#define BUILTIN_OFF *stateptr = *stateptr & ~(BUILTIN);
#define HISTERROR_OFF *stateptr = *stateptr & ~(HISTERROR);
#define TURN_BACKGROUND_OFF *stateptr = *stateptr & ~(BACKGROUND);
#define TURN_REDIRECTION_OFF *stateptr = *stateptr & ~(REDIRECTION);
#define TURN_PIPE_OFF *stateptr = *stateptr & ~(PIPE);

#define NO_HISTERROR !(HISTERROR & *stateptr)
#define IS_IN_BACKGROUND (BACKGROUND & *stateptr)
#define IS_REDIRECT (REDIRECTION & *stateptr)
#define IS_PIPED (PIPE & *stateptr)

#endif // DEFS
