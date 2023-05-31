/*
 ============================================================================
 Name        : LinkedList.h
 Author      : Bassam Mamdouh Mohammed
 Version     : 1.0.0
 Copyright   : LinkedIn: https://www.linkedin.com/in/bassam-mamdouh
 Description : Hello World in C, Ansi-style
 Created on: May 29, 2023
 ============================================================================
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK  	     (0x01)
#define NOK          (0x00)
#define NULL_POINTER (0x02)
#define DOUBLE    0x02
#define SINGLE    0x01
#define CIRCULAR  0x03
#define LINKEDLIST_TYPE  (DOUBLE)
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

struct Node{
	uint32_t Data;
#if (LINKEDLIST_TYPE==SINGLE)
	struct Node *NodeLink;
#else
	struct Node *PrevNodeLink;
	struct Node *NextNodeLink;
#endif
};
#if (LINKEDLIST_TYPE==SINGLE)
void SingleLinkedlist_InsertAtBeginning(struct Node **List);
void SingleLinkedlist_InsertAtEnding(struct Node **List);
void SingleLinkedList_InsertAfterNode(struct Node *List);
#elif (LINKEDLIST_TYPE==DOUBLE)
void DoubleLinkedList_InsertAtBeginning(struct Node **List, uint32_t Data);
void DoubleLinkedList_InsertAtEnding(struct Node *List, uint32_t Data);
void DoubleLinkedList_InsertAfterNode(struct Node *List, uint32_t Data, uint32_t Posn);
void DoubleLinkedList_DeleteNodeAtBeginning(struct Node **List);
void DoubleLinkedList_DeleteNodeAtEnding(struct Node *List);
void DoubleLinkedList_DeleteNodeAtPosition(struct Node *List, uint32_t Posn);
#elif (LINKEDLIST_TYPE==CIRCULAR)

#else

#endif
#endif /* LINKEDLIST_H_ */
