/*
 ============================================================================
 Name        : stack.c
 Author      : Bassam Mamdouh Mohammed
 Version     : 1.0.0
 Copyright   : LinkedIn: https://www.linkedin.com/in/bassam-mamdouh
 Description : Hello World in C, Ansi-style
 Created on  : May 23, 2023
 ============================================================================
 */

#include "DS_stack.h"

static uint8_t StackFull(Stack_t *stack);
static uint8_t StackEmpty(Stack_t *stack);

Stack_t *StackCreate(uint32_t size, uint8_t *status)
{
	Stack_t *stack = NULL;
    if(NULL == status)
    {
        *status = NOK;
    }
    else
    {
    	stack = (Stack_t *)malloc(sizeof(Stack_t));
    	if(!stack)
    	{
    		*status = NOK;
    	}
    	else
    	{
    		stack->elementCount = 0;
    		stack->stackPointer = -1;
    		stack->maxSize = size;
    		stack->stackArray = (void **)calloc(stack->maxSize,sizeof(void *));
    		if(NULL == stack->stackArray)
    		{
    			status = NOK;
    			free(stack);  // realloc(stack,0); prevent dangling pointer
    			stack = NULL;
    		}
    		else
    		{
    			*status = OK;
    		}
    	}
    }
    return stack;
}
Stack_t *StackDestroy(Stack_t *stack, uint8_t *status)
{
	    if((NULL == stack) || (NULL == status))
	    {
	        *status = NOK;
	    }
	    else
	    {
	    	free(stack->stackArray);
	    	free(stack);
	    	*status = OK;
	    }
	return NULL;
}
void *StackPop(Stack_t *stack, uint8_t *status)
{
    void *dataOut = NULL;
    if((NULL == stack) || (NULL == status))
    {
        *status = NOK;
    }
    else
    {
    	if(EMPTY == StackEmpty(stack))
    	{
    		*status = EMPTY;
    	}
    	else
    	{
    		dataOut = (stack->stackArray[stack->stackPointer]);
    		--(stack->stackPointer);
    		--(stack->elementCount);
    	    *status = OK;
    	}
    }
    return dataOut;
}

uint8_t StackPush(Stack_t *stack, void *value)
{
	uint8_t status;
    if((NULL == stack) || (NULL == value))
    {
        status = NOK;
    }
    else
    {
    	if(StackFull(stack))
    	{
    		status = FULL;
    	}
    	else
    	{
    		++(stack->stackPointer);
    		stack->stackArray[stack->stackPointer] = value;
    		++(stack->elementCount);
    	    status = OK;
    	}
    }
    return status;
}
void *StackTop(Stack_t *stack, uint8_t *status)
{
	void *dataTop = NULL;
    if((NULL == stack) || (NULL == status))
    {
        *status = NOK;
    }
    else
    {
    	if(EMPTY == StackEmpty(stack))
    	{
    		*status = EMPTY;
    	}
    	else
    	{
    		dataTop = stack->stackArray[stack->stackPointer];
    		*status = NOK;
    	}
    }
    return dataTop;
}

static uint8_t StackFull(Stack_t *stack)
{
    if((MAX_SIZE-1) == stack->stackPointer)
    {
        return FULL;
    }
    else
    {
        return NOTFULL;
    }
}

static uint8_t StackEmpty(Stack_t *stack)
{
    if(-1 == stack->stackPointer)
    {
        return EMPTY;
    }
    else
    {
        return NOTFULL;
    }
}
