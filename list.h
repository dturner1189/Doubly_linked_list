#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    unsigned char char_data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *initializeNode_Empty();
Node *initializeNode_Char(unsigned char c);
int compareNode(unsigned char L, unsigned char R);
int searchNode(unsigned char c);
void insertNode(unsigned char to_insert);
Node *returnPointerElement(unsigned char c);
int Exist(unsigned char c);
void deleteNode(unsigned char c);
void cleanList();
void printNode();

#endif
