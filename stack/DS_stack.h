/*
 ============================================================================
 Name        : stack.h
 Author      : Bassam Mamdouh Mohammed
 Version     : 1.0.0
 Copyright   : LinkedIn: https://www.linkedin.com/in/bassam-mamdouh
 Description : stack data structure header file bsed on array
 Created on  : May 23, 2023
 ============================================================================
 */

#ifndef DS_STACK_H_
#define DS_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOK          (0x00)
#define OK           (0x01)
#define NULL_PONTER  (0x02)
#define FULL         (0x03)
#define EMPTY        (0x04)
#define NOTFULL      (0x05)
#define NULL_POINTER (0x06)
#define MAX_SIZE     (0x05)

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef struct{
    void **stackArray;
    sint32_t elementCount;
    uint32_t maxSize;
    sint32_t stackPointer;
}Stack_t;

Stack_t *StackCreate(uint32_t size, uint8_t *status);
Stack_t *StackDestroy(Stack_t *stack, uint8_t *status);
void *StackPop(Stack_t *stack, uint8_t *status);
uint8_t StackPush(Stack_t *stack, void *value);
void *StackTop(Stack_t *stack, uint8_t *status);

#endif /* DS_STACK_H_ */
