#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define ERR_PTR 13.0
#define STACK_COEFF 1.5
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2


typedef struct stack
{
    double* data;
    size_t size;
    size_t capacity;
}; stack

void StackCtor(stack* stk, size_t capacity)
{
    assert(stk != NULL);
    stk->data = (double*)calloc(capacity, sizeof(stk->[0]));
    stk->capacity = capacity;
    stk->size = 0;
}

void StackDtor(stack* stk)
{
    assert(stk);
    free(stk->data);
    //stk->data = ERR_PTR;
}

int StackResize(stack* stk)
{
    stk->size *= STACK_COEFF;
    stk->data = (double*)realloc(stk->data, (stk->size)*sizeof(stk->data[0]));
    if (stk->data == 0)
        return STACK_OVERFLOW;
}

void StackPush(stack* stk, double value)
{
    assert(stk);
    if(stk->size >= stk->capacity)
    {
        StackResize(stk);
    }
        stk->data[stk->size++] = value;
}

double StackPop(stack* stk)
{
    if (stk->size == 0)
        return STACK_UNDERFLOW;
    else
        stk->size--;
    return stk->data[stk->size];
}



int main()
{
    stack stk = {};
    StackCtor(&stk, 10);
    StackPush(&stk, 10);
    printf("%f", StackPop(&stk));
    StackDtor(&stk);
    return 0;
}
