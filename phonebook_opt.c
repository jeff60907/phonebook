#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook_opt.h"
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
/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
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
