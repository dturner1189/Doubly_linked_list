#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *head = NULL;

Node *initializeNode_Empty() {
    Node* node = malloc(sizeof(*node));
    if (node != NULL) {
        node->char_data = '\0';
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

Node *initializeNode_Char(unsigned char c) {
    Node *node = malloc(sizeof(*node));
    if (node != NULL) {
        node->char_data = c;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

int compareNode(unsigned char L, unsigned char R) {
    if (L < R) {
        return 1;
    }
    else if (R < L) {
        return -1;
    }
    else if (R == L) {
        return 0;
    }
}

int searchNode(unsigned char c) {
    Node *itr = head;
    int position_index = 0;

    while (itr != NULL) {
        if (compareNode(c, itr->char_data) == -1) {
            itr=itr->next;
            position_index++;
        }
        else {
            break;
        }

    } // end of looping with itr
    return position_index;
}

void insertNode(unsigned char to_insert) {
    printf("\nAttempting to insert %c....", to_insert);

    if (head == NULL) {
        head = initializeNode_Char(to_insert);
        printf(" New head created.\n");
    }
    else {
        int result = compareNode(head->char_data, to_insert);

        switch (result) {
            case 1: {
                int found_at = searchNode(to_insert);
                Node *temp = head;

                for (int i = 0; i < found_at - 1; i++) {
                    temp = temp->next;
                }

                Node *a = initializeNode_Char(to_insert);
                Node *b = temp->next;

                a->prev = temp;
                a->next = b;

                temp->next = a;

                if (b != NULL) {
                    b->prev = a;
                }

                break;
            }
            case 0:
            case -1: {
                Node *temp = initializeNode_Char(to_insert);
                temp->next = head;
                temp->prev = NULL;

                head->prev = temp;
                head = temp;
                break;
            }

        } // end of switch
    } // end of else
    printf(" Node created.\n" );

}

Node *returnPointerElement(unsigned char c) {
    Node *itr = head;

    while (itr != NULL) {

        if (compareNode(c, itr->char_data) == 0) {
            return itr;
            break;
        }
        else {
            itr = itr->next;
        }
    } // end of looping with itr

}

int Exist(unsigned char c) {
    Node *itr = head;
    int exists = 0;

    while (itr != NULL) {

        if (compareNode(c, itr->char_data) == 0) {
            return 1;
            break;
        }
        else {
            itr = itr->next;
        }
    } // end of looping with itr
    return exists;
}

void deleteNode(unsigned char c) {
    if (!(Exist(c))) {
        printf("\nInvalid element to delete...\n");
        return;
    }

    Node *remove_me = returnPointerElement(c);

    printf("\nAttempting to delete %c....", remove_me->char_data);

    if (head == NULL || remove_me == NULL) {
        printf("\nInvalid Removal...\n");
    }

    if (head == remove_me) {
        printf("\nRemoving Head of List..." );
        head = remove_me->next;
        free(remove_me);
        printf(" Head Deleted.\n");
        return;
    }

    if (remove_me->next != NULL) {
        remove_me->next->prev = remove_me->prev;
    }

    if (remove_me->prev != NULL) {
        remove_me->prev->next = remove_me->next;
        free(remove_me);
        printf(" Element Deleted.\n");
    }
}

void cleanList() {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printNode() {
    Node *itr = head;
    while (itr != NULL) {
        printf("\nData in node: %c.", itr->char_data);
        if (itr->next == NULL) {
            break;
        }
        else {
            itr = itr->next;
        }
    }
    printf("\n");
}
