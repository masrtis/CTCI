//You're given two linked lists. They represent backwards decimal numbers. 256 would be represented as 6->5->2.
//Add these linked lists.


//There are 2 main "gotchas" that come to mind. The first is the carry. The second is that one number
//can be many orders of magnitude larger than the other, so there's essentially a point at
//which one number is no longer being added, but carrying still needs to take place.
//I don't want to implement carrying in 2 spots, so I'm going to pull some hacky bullshit.

#include "listHelpers.h"
#include <iostream>

using namespace std;

node * AddLists( node * one, node * two )
{
    node * outHead = NULL; //to return
    node * out = NULL; //to iterate
    int carry = 0;

    while( true )
    {
        int sum = 0;

        if( one != NULL )
        {
            sum += one->data;
        }

        if( two != NULL )
        {
            sum += two->data;
        }
        else if( one == NULL )
        {
            break;
        }
        sum += carry;

        node * temp = new node;
        //I want to create a node as I populate it. This requires special casing the head.
        if( outHead == NULL )
        {
            outHead = temp;
            out = temp;
        }
        out->next = temp;
        out = out->next;

        carry = sum > 9 ? 1: 0;
        out->data = sum % 10;

        //conditional advance
        one = one==NULL? one: one->next;
        two = two==NULL? two: two->next;
    }

    if( carry )
    {
        out->next = new node;
        out = out->next;
        out->data = 1;
    }

    out->next = NULL;
    return outHead;
}

//After implementing the above, I basically realized I was an idiot, and that I could just use powers of 10 to create
//the sum and them break it back down. So let's do that.
int ListToInt( node * n )
{
    int sum = 0;
    int magnitude = 1;
    while( n != NULL )
    {
        sum += n->data * magnitude;
        n = n->next;
        magnitude *= 10;
    }
    return sum;
}
node * AddListsSmarter( node* one, node* two )
{
    int sum = ListToInt( one ) + ListToInt( two );
    // int magnitude = 1;

    node * outHead = NULL;
    node * out = NULL;

    while( sum != 0 )
    {
        node * temp = new node;
        if( outHead == NULL )
        {
            outHead = temp;
            out = temp;
        }
        out->next = temp;
        out = out->next;

        out->data = sum % 10;
        sum /= 10;

        // magnitude *= 10;
    }
    out->next = NULL;//cap the tail
    return outHead;
}

int main()
{
    //Set up some test list
    node * head1 = new node;
    head1->data = 0;
    node * tail1 = head1;
    for( int i = 1; i < 3; ++i )
    {
        tail1->next = new node;
        tail1 = tail1->next;
        tail1->data = i % 5;
    }
    tail1->next = NULL;

    node * head2 = new node;
    head2->data = 5;
    node * tail2 = head2;

    tail2->next = new node;
    tail2 = tail2->next;
    tail2->data = 9;
    tail2->next = NULL;

    printList( head1 );
    printList( head2 );
    // printList( AddLists( head1, head2 ) );
    printList( AddListsSmarter( head1, head2 ) );
    getchar();
    return 0;
}