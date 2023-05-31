/*
 ============================================================================
 Name        : Queue.c
 Author      : Bassam Mamdouh Mohammed
 Version     : 1.0.0
 Copyright   : LinkedIn: https://www.linkedin.com/in/bassam-mamdouh
 Description : Circular Queue source file provides different queue functionalities
 Created on  : May 31, 2023
 ============================================================================
 */
#include "../inc/Queue.h"

queue_t *QueueCreate(uint32_t size, uint32_t *status)
{
	queue_t *NewQueue = NULL;
	*status = OK;
	NewQueue = (queue_t *)malloc(sizeof(queue_t));
	if(NULL != NewQueue)
	{
		NewQueue->queueArray = (void **)calloc(size,sizeof(void *));
		if(NULL != NewQueue->queueArray)
		{
			NewQueue->queueSize = size;
			NewQueue->queueElmenets = 0;
			NewQueue->queueFront = -1;
			NewQueue->queueRear = -1;
		}
		else
		{
			*status = NOK;
		}
	}
	else
	{
		*status = NULL_POINTER;
	}
	return NewQueue;
}
uint8_t QueueDestroy(queue_t *Queue)
{
	uint8_t retval = OK;
	if(NULL != Queue)
	{
		free(Queue->queueArray);
		free(Queue);
	}
	else
	{
		retval = NOK;
	}
	return retval;
}
uint8_t Enqueue(queue_t *Queue, void *item)
{
	uint8_t retval = OK;
	if((NULL == Queue) || (NULL == item))
	{
		retval = NULL_POINTER;
	}
	else
	{
		if(Queue->queueElmenets != Queue->queueSize)
		{
			if(Queue->queueRear == Queue->queueSize)
			{
				Queue->queueRear = 0;
			}else{}
			Queue->queueArray[Queue->queueRear] = item;
			if(0 == Queue->queueElmenets)
			{
				Queue->queueElmenets = 1;
				Queue->queueFront = 0;
			}
			else
			{
				++(Queue->queueElmenets);
			}
		}
		else
		{
			retval = FULL;
		}
	}
	return retval;
}
uint8_t Dequeue(queue_t *Queue)
{
	void *DequeueItem = NULL;
	uint8_t retval = OK;
	if(NULL == Queue)
	{
		retval = NULL_POINTER;
	}
	else
	{
		if(Queue->queueElmenets != 0)
		{
			DequeueItem = Queue->queueArray[Queue->queueFront];
			++(Queue->queueFront);
			if(Queue->queueFront == Queue->queueSize)
			{
				Queue->queueFront = 0;
			}else{}
			if(1 == Queue->queueElmenets)
			{
				Queue->queueFront = -1;
				Queue->queueRear = -1;
			}
			else
			{
				--(Queue->queueElmenets);
			}
		}
		else
		{
			DequeueItem = NULL;
			retval = EMPTY;
		}
	}
	return retval;
}
void *QueueFront(queue_t *Queue, uint8_t *status)
{
	void *frontItem = NULL;
	*status = OK;
	if((NULL == Queue) || (NULL == status))
	{
		*status = NULL_POINTER;
	}
	else
	{
		if(0 != Queue->queueElmenets)
		{
			frontItem = Queue->queueArray[Queue->queueFront];
		}
		else
		{
			*status = EMPTY;
		}
	}
	return frontItem;
}
void *QueueRear(queue_t *Queue, uint8_t *status)
{
	void *rearItem = NULL;
	*status = OK;
	if((NULL == Queue) || (NULL == status))
	{
		*status = NULL_POINTER;
	}
	else
	{
		if(0 != Queue->queueElmenets)
		{
			rearItem = Queue->queueArray[Queue->queueRear];
		}
		else
		{
			*status = EMPTY;
		}
	}
	return rearItem;
}
uint8_t QueueElements(queue_t *Queue, uint32_t *elements)
{
	uint8_t retval = OK;
	if((NULL == Queue) || (NULL == elements))
	{
		retval = NULL_POINTER;
	}
	else
	{
		if(0 != Queue->queueElmenets)
		{
			*elements = Queue->queueElmenets;
		}
		else
		{
			retval = EMPTY;
		}
	}
	return retval;
}
