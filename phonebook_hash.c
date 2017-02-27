#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook_hash.h"
#include "memory_pool.h"

static memory_pool *pool = NULL;

void init_memorypool(int size)
{
    pool = pool_init(size);
}

void free_memorypool(void)
{
    pool_free(pool);
}


entry *findName(char lastName[], entry *pHead)
{
    while(pHead != NULL) {
        if(strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) pool_alloc(pool, sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}

unsigned int BKDRHash(char *str)
{
    unsigned int hash = 0;
    while (*str) {
        hash = hash * 131 + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}
