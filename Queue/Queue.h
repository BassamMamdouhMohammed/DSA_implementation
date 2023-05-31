/*
 ============================================================================
 Name        : Queue.h
 Author      : Bassam Mamdouh Mohammed
 Version     : 1.0.0
 Copyright   : LinkedIn: https://www.linkedin.com/in/bassam-mamdouh
 Description : Circular Queue header file provides functions prototype & user data types
 Created on  : May 31, 2023
 ============================================================================
 */
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK  	     (0x01)
#define NOK          (0x00)
#define NULL_POINTER (0x02)
#define FULL         (0x03)
#define EMPTY        (0x04)

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef signed int sint32_t;

typedef struct{
	void **queueArray;
	uint32_t queueSize;
	sint32_t queueElmenets;
	sint32_t queueFront;
	sint32_t queueRear;
}queue_t;

queue_t *QueueCreate(uint32_t size, uint32_t *status);
uint8_t QueueDestroy(queue_t *Queue);
uint8_t Enqueue(queue_t *Queue, void *item);
uint8_t Dequeue(queue_t *Queue);
void *QueueFront(queue_t *Queue, uint8_t *status);
void *QueueRear(queue_t *Queue, uint8_t *status);
uint8_t QueueElements(queue_t *Queue, uint32_t *elements);
#endif /* QUEUE_H_ */
