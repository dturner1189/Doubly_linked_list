#include "list.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Insert elements
    insertNode('E');
    insertNode('L');
    insertNode('B');
    insertNode('D');
    insertNode('F');
    insertNode('A');
    insertNode('G');
    insertNode('H');
    insertNode('J');
    insertNode('C');
    insertNode('K');
    insertNode('I');

    // show results
    printNode();

    // remove a few
    deleteNode('J');
    deleteNode('D');
    deleteNode('G');

    // reprint
    printNode();

    // delete tail
    deleteNode('L');
    // reprint
    printNode();

    // delete invalid element
    deleteNode('7');

    // reprint
    printNode();

    // delete head
    deleteNode('A');
    // reprint
    printNode();

    // insert a repeat value
    insertNode('K');
    // reprint
    printNode();

    // insert crazy values
    insertNode('6');
    insertNode('&');
    insertNode('\\');
    insertNode('!');
    // reprint
    printNode();

    // insert wrong values
    //insertNode("gg5");
    //insertNode(5);
    // reprint
    //printNode();

    cleanList();
    return 0;
}
