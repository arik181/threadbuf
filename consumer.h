#include "defs.h"

typedef struct consumer * consumerptr;

struct consumer
{
        int tid;
};

consumerptr initconsumer();
int openbuffer();
int consume();
