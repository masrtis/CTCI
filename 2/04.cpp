//Given a linked list and a value x, partition the linked list into 2 parts
//A part where everything is less than x
//A part where they're x or greater
//All other ordering is unimportant

//Comments: there should be multiple ways to do this in O(n).
//One obvious way is to go through looking at the guy to your right.
//If it's less than x, make it the new head. Once the next guy is NULL, that's the end.

#include <iostream>
#include "listHelpers.h"

using namespace std;

//Function will return the new head
node * PartitionOn( node * head, int x )
{
    node * n = head;

    while( n->next != NULL )
    {
        if( n->next->data < x )
        {
            node * temp = n->next;
            n->next = temp->next;

            temp->next = head;
            head = temp;
        }
        else
            n = n->next;
    }
    return head;
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
        tail->data = i % 5;
    }
    tail->next = NULL;
    printList( head );

    head = PartitionOn( head, 3 );
    printList( head );
    getchar();
    return 0;
}