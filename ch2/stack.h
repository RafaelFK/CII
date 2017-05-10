#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#define T Stack_T
typedef struct T *T;

T stack_new(void);
int Stack_empty(T stk);
void Stack_push(T stk, void *x);
void *Stack_pop(T stk);
void Stack_free(T *stk); // Takes a reference to the pointer so as to deallocate its stack and set it to null,
                         // avoiding dangling pointers
#undef T
#endif