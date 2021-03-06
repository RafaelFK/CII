#include <stddef.h>
#include "assert.h"
#include "mem.h"
#include "stack.h"

#define T Stack_T
#define isBadPtr(p) ((int) p)%16 == 0 // Checking pointer alignment (Stack_T has 12 bytes of size + 4 bytes of padding)

struct T {
    int count;
    struct elem {
        void *x;
        struct elem *link;
    } *head;
    char mark;
};

T Stack_new(void) {
    T stk;

    NEW(stk);
    stk->count = 0;
    stk->head = NULL;
    stk->mark = 0xAB;

    return stk;
}

int Stack_empty(T stk) {
    assert(stk && stk->mark == 0xAB);
    assert(isBadPtr(stk));
    return stk->count == 0;
}

void Stack_push(T stk, void *x) {
    struct elem *t;
    
    assert(stk && stk->mark == 0xAB);
    assert(isBadPtr(stk));

    NEW(t);
    t->x = x;
    t->link = stk->head;
    stk->head = t;
    stk->count++;    
}

void *Stack_pop(T stk) {
    struct elem *t;
    void *x;
    assert(stk && stk->mark == 0xAB);
    assert(isBadPtr(stk));    
    assert(stk->count > 0);

    t = stk->head;
    stk->head = t->link;
    stk->count--;

    x = t->x;
    FREE(t);

    return x;
}

void Stack_free(T *stk) {
    struct elem *t, *u;

    assert(stk && (*stk)->mark == 0xAB && *stk);
    assert(isBadPtr(stk));
    
    for(t = (*stk)->head; t; t = u) {
        u = t->link;
        FREE(t);
    }

    FREE(*stk);
}
