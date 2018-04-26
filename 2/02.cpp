//Write an algorithm to return the kth to last node in the list. k=0 would be the dead last, k=1 is the one before that, etc.

//This can def be done in order n using 2 different methods -- either 2 passes over the list,
//the first to count and the 2nd to pull the kth from last.
//Another method is to send 2 runners at the same time, a distance k apart. Neither one is obviously more efficient.
//I'll do the 2nd

#include "listHelpers.h"
#include <iostream>

using namespace std;

//if the 10th from last element is asked for in a 2-element list, the head will be returned.
node * ReturnKFromLast(node * head, int k)
{
    node * lead = head;

    //prepare to start the slow runner
    for( size_t i=0; i < k; ++i)
    {
        if( lead->next == NULL )
            return head;
        lead = lead->next;
    }

    node * follow = head;

    while( lead->next != NULL )
    {
        lead = lead->next;
        follow = follow->next;
    }
    return follow;
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

    cout << ReturnKFromLast( head, 100 )->data << endl;
    cout << ReturnKFromLast( head, 0 )->data << endl;
    cout << ReturnKFromLast( head, 1 )->data << endl;
    cout << ReturnKFromLast( head, 2 )->data << endl;

    getchar();
    return 0;
}