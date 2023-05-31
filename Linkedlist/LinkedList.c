/*
 ============================================================================
 Name        : LinkedList.c
 Author      : Bassam Mamdouh Mohammed
 Version     : 1.0.0
 Copyright   : LinkedIn: https://www.linkedin.com/in/bassam-mamdouh
 Description : Singular and Double Linkedlist implementation
 Created on  : May 29, 2023
 ============================================================================
 */
#include "../inc/LinkedList.h"


#if (LINKEDLIST_TYPE==SINGLE)
static uint32_t SingleLinkedList_GetLength(struct Node *List);
void SingleLinkedlist_InsertAtBeginning(struct Node **List)
{
	struct Node *NewNode = NULL;
	NewNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != NewNode)
	{
		printf("Enter Node Data: ");
		scanf("%i",&NewNode->Data);

		if(NULL == *List)
		{
			NewNode->NodeLink = NULL;
			*List = NewNode;
		}
		else
		{
			NewNode->NodeLink = *List;
			*List = NewNode;
		}
	}
	else
	{
		printf("Sorry, No sufficient memory space!! \n");
	}
}
void SingleLinkedlist_InsertAtEnding(struct Node **List)
{
	struct Node *NewNode = NULL;
	struct Node *TailNode = NULL;
	NewNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != NewNode)
	{
		printf("Enter Node Data: ");
		scanf("%i",&NewNode->Data);
		NewNode->NodeLink = NULL;
		if(NULL == *List)
		{
			*List = NewNode;
		}
		else
		{
			TailNode = *List;
			while(NULL != TailNode->NodeLink)
			{
				TailNode = TailNode->NodeLink;
			}
			TailNode->NodeLink = NewNode;
		}
	}
	else
	{
		printf("Sorry, No sufficient memory space!! \n");
	}
}
void SingleLinkedList_InsertAfterNode(struct Node *List)
{
	struct Node *NewNode = NULL;
	struct Node *CounterNode = NULL;
	uint32_t NodePosn  = 0;
	uint32_t ListLen   = 0;
	uint32_t NodeIndex = 1;

	printf("Enter Node Position: ");
	scanf("%i",&NodePosn);
	ListLen = SingleLinkedList_GetLength(List);
	if(NodePosn > ListLen)
	{
		printf("Invalid Node Position, the list length is %i ",ListLen);
	}
	else
	{
		CounterNode = List;
		while(NodeIndex < NodePosn)
		{
			++NodeIndex;
			CounterNode = CounterNode->NodeLink;
		}
		NewNode = (struct Node*)malloc(sizeof(struct Node));
		if(NULL != NewNode)
		{
			printf("Enter Node Data: ");
			scanf("%i",&NewNode->Data);
			NewNode->NodeLink = CounterNode->NodeLink;
			CounterNode->NodeLink = NewNode;
		}
		else
		{
			printf("Sorry, No sufficient memory space!! \n");
		}
	}
}
static uint32_t SingleLinkedList_GetLength(struct Node *List)
{
	uint32_t Length = 0;
	struct Node *TempNode = List;
	while(NULL != TempNode)
	{
		++Length;
		TempNode = TempNode->NodeLink;
	}
	return Length;
}
#elif (LINKEDLIST_TYPE==DOUBLE)
void DoubleLinkedList_InsertAtBeginning(struct Node **List, uint32_t Data)
{
	struct Node *NewNode = NULL;
	NewNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != NewNode)
	{
		NewNode->Data = Data;
		if(NULL == *List)
		{
			NewNode->NextNodeLink = NULL;
			NewNode->PrevNodeLink = NULL;
			(*List) = NewNode;
		}
		else
		{
			NewNode->NextNodeLink = (*List);
			NewNode->PrevNodeLink = NULL;
			(*List)->PrevNodeLink = NewNode;
			(*List) = NewNode;
		}
	}
	else
	{
		printf("Sorry, no sufficient memory space!! \n");
	}
}
void DoubleLinkedList_InsertAtEnding(struct Node *List, uint32_t Data)
{
	struct Node *NewNode = NULL;
	struct Node *TailNode = NULL;
	NewNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != NewNode)
	{
		NewNode->Data = Data;
		TailNode = List;
		if(NULL == List)
		{
			NewNode->NextNodeLink = NULL;
			NewNode->PrevNodeLink = NULL;
			List = NewNode;
		}
		else
		{
			while(NULL != TailNode->NextNodeLink)
			{
				TailNode = TailNode->NextNodeLink;
			}
			NewNode->NextNodeLink = NULL;
			TailNode->NextNodeLink = NewNode;
			NewNode->PrevNodeLink = TailNode;
		}
	}
	else
	{
		printf("Sorry, no sufficient memory space!! \n");
	}
}
void DoubleLinkedList_InsertAfterNode(struct Node *List, uint32_t Data, uint32_t Posn)
{
	struct Node *NewNode = NULL;
	struct Node *CounterNodeOne = NULL;
	struct Node *CounterNodeTwo = NULL;
	while(Posn != 1)
	{
		CounterNodeOne = CounterNodeOne->NextNodeLink;
		--Posn;
	}
	NewNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != NewNode)
	{
		NewNode->Data = Data;
		if(NULL == CounterNodeOne->NextNodeLink)
		{
			CounterNodeOne->NextNodeLink = NewNode;
			NewNode->NextNodeLink = NULL;
			NewNode->PrevNodeLink = CounterNodeOne;
		}
		else
		{
			CounterNodeTwo = CounterNodeOne->NextNodeLink;
			CounterNodeOne->NextNodeLink = NewNode;
			CounterNodeTwo->PrevNodeLink = NewNode;
			NewNode->PrevNodeLink = CounterNodeOne;
			NewNode->NextNodeLink = CounterNodeTwo;
		}
	}
	else
	{
		printf("Sorry, No sufficient memory space!! \n");
	}
}
void DoubleLinkedList_DeleteNodeAtBeginning(struct Node **List)
{
	*List = (*List)->NextNodeLink;
	free((*List)->PrevNodeLink);
	(*List)->PrevNodeLink = NULL;
}
void DoubleLinkedList_DeleteNodeAtEnding(struct Node *List)
{
	struct Node *CounterNodeOne = List;
	struct Node *CounterNodeTwo = NULL;
	while(NULL != CounterNodeOne->NextNodeLink)
	{
		CounterNodeOne = CounterNodeOne->NextNodeLink;
	}
	CounterNodeTwo = CounterNodeOne->PrevNodeLink;
	CounterNodeTwo->NextNodeLink = NULL;
	free(CounterNodeOne);
	CounterNodeOne = NULL;
}
void DoubleLinkedList_DeleteNodeAtPosition(struct Node *List, uint32_t Posn)
{
	struct Node *CounterNodeOne = List;
	struct Node *CounterNodeTwo = NULL;
	while(Posn > 1)
	{
		CounterNodeOne = CounterNodeOne->NextNodeLink;
		--Posn;
	}
	CounterNodeTwo = CounterNodeOne->PrevNodeLink;
	CounterNodeTwo->NextNodeLink = CounterNodeOne->NextNodeLink;
	CounterNodeOne->NextNodeLink->PrevNodeLink = CounterNodeTwo;
	free(CounterNodeOne);
	CounterNodeOne = NULL;
}
#elif (LINKEDLIST_TYPE==CIRCULAR)

#else

#endif
