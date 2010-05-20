#include <pthread.h>
#include <stdio.h>

/*** All of the code in this file comes from a 
 * class handout. I just wanted to code it myself to 
 * explore the issue and perhaps play with it a bit.
 * ***/

int sum; 
void * runner (void * param); // the thread

int main(int argc, char ** argv)
{
        pthread_t tid;
        pthread_attr_t attr;

        if (argc != 2)
        {
            fprintf(stderr, "usage: a.out <integer value>\n");
            return -1;
        }

        if (atoi(argv[1]) < 0)
        {
            fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
            return -1;
        }

        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, argv[1]);
        pthread_join(tid, NULL);

        printf("sum = %d\n", sum);
}

/*** The thread ***/
void * runner (void * param)
{
    int i=0; 
    int upper = atoi(param);
    sum = 0;

    for(i=1;i<=upper;++i)
            sum += i;

    pthread_exit(0);
}

