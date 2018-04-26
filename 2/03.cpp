//Given a pointer to some (guaranteed) middle node in a forward linked list, delete that node
//You are not allowed a pointer to the head

//This is going to be some inefficient dominoe shit, where I have take things from the later list
//and bump them left.
//I can choose to move the pointers left, or the data. In this case the data is an int, and it's easier
//to not think about the pointers, so I'm doing that.

#include "listHelpers.h"
#include <iostream>

using namespace std;

void DeleteNode( node * target )
{
    while( target->next->next != NULL )
    {
        target->data = target->next->data;
        target = target->next;
    }

    target->data = target->next->data;

    delete target->next;
    target->next = NULL;
}

int main()
{
    //Set up some test list
    node * head = new node;
    head->data = 0;
    node * tail = head;
    for( int i = 1; i < 15; ++i )
    {
        tail->next = new node;
        tail = tail->next;
        tail->data = i;
    }
    tail->next = NULL;
    printList( head );

    DeleteNode( head->next->next->next );//delete "3" node
    DeleteNode( head->next->next->next );//delete "4" node
    printList( head );
    getchar();
    return 0;
}