//Q: Given a linked list with a cycle, return the first node in the cycle.

//The answer to this, which I looked up on wikipedia, turns out to be floyd's algorithm

#include "listHelpers.h"
node * Floyd( node * head )
{
    node * slow = head;
    node * fast = head;
    //I'm leaving off the guards and assuming there IS a cycle
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while( slow != fast );
    
    slow = head;
    while( slow != fast )
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

#include <iostream>
using namespace std;
int main()
{
    node * head1 = new node;
    head1->data = 0;
    node * tail1 = head1;
    for( int i = 1; i < 10; ++i )
    {
        tail1->next = new node;
        tail1 = tail1->next;
        tail1->data = i;
    }
    //connect back at node 5
    tail1->next = head1->next->next->next->next->next;

    cout << "first node in the cycle is " << Floyd( head1 )->data << endl;

    getchar();
    return 0;
}