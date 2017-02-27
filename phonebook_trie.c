#include <stdlib.h>
#include <string.h>
#include "phonebook_trie.h"
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
    int i, alpha;
    int len = strlen(lastName);
    for(i = 0; i <= len && pHead; i++) {
        if(lastName[i] >= 'a')
            alpha = lastName[i] - 'a';
        else if(lastName[i] >= 'A')
            alpha = lastName[i] -'A';
        else
            alpha = 26;

        pHead = pHead->pChild[alpha];
    }
    return pHead;
}

void append(char lastName[], entry *pHead)
{
    int i, alpha;
    int len = strlen(lastName);
    for (i = 0; i <= len; i++) {
        if (lastName[i] >= 'a')
            alpha = lastName[i] - 'a';
        else if (lastName[i] >= 'A')
            alpha = lastName[i] - 'A';
        else
            alpha = 26;
        if(pHead->pChild[alpha] == NULL) {
            pHead->pChild[alpha] = (entry *) pool_alloc(pool, sizeof(entry));
            pHead->pChild[alpha]->ch = lastName[i];
        }
        pHead = pHead->pChild[alpha];
    }
}
/*
void free_trie(entry *pHead)
{
    if(pHead == NULL)
        return;
    int i;
    for(i = 0; i < 27; i++)
        free_trie(pHead->pChild[i]);
    free(pHead);
}*/

