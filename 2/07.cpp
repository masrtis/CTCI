//Q: Given two singly linked lists, determine if they intersect. Return the intersecting noden.
//Intersection here is based on reference -- not value.
//If the kth node in the first list is the jth node in the second, they intersect.


//OK, what happens if two lists intersect? Either they will terminate at the same node,
//or they'll both get caught in the same cycle. I'm assuming neither has a cycle.


#include "listHelpers.h"

node * AdvanceByN( node * head, int n )
{
    while( n > 0 )
    {
        head = head->next;
        --n;
    }
    return head;
}

node * IntersectionOf( node * head1, node * head2 )
{
    //there can be no intersection if either list is len 0. This guard is actually just here to make the while loops nicer below
    if( head1 == NULL || head2 == NULL )
        return NULL;
    node * n1 = head1;
    node * n2 = head2;

    int len1 = 1;
    int len2 = 1;

    while( n1->next != NULL )
    {
        n1 = n1->next;
        ++len1;
    }
    while( n2->next != NULL )
    {
        n2 = n2->next;
        ++len2;
    }
    //if they don't share a tail
    if( n1 != n2 )
        return NULL;

    //okay, now I need to advance the longer list so both lists are the same distance from the intersection node.
    n1 = head1;
    n2 = head2;
    if( len1 > len2 )
        n1 = AdvanceByN( n1, len1 - len2 );
    else
        n2 = AdvanceByN( n2, len2 - len1 );

    //I'm now guaranteed that the next loop will end
    while( n1 != n2 )
    {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
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
    tail1->next = NULL;
    printList( head1 );

    node * head2 = new node;
    head2->data = 0;
    node * tail2 = head2;
    for( int i = 1; i < 4; ++i )
    {
        tail2->next = new node;
        tail2 = tail2->next;
        tail2->data = i;
    }
    //connect the lists at list1 = 4
    tail2->next = head1->next->next->next->next;
    printList( head2 );

    cout << "Intersection is " << ( IntersectionOf(head1, head2) )->data << endl;

    getchar();
    return 0;
}