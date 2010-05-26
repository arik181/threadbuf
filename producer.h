#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "defs.h"
#include "queue.h"
#include "slot.h"
#include "package.h"

#ifndef PRODUCER
#define PRODUCER

int produce(packageptr thepackage);

#endif // PRODUCER
