//Q: Implement a function to check if a list is a palindrome


//How do I not do this in n^2 time? Palindrome will have every element appear an even # of times
//except maybe 1 of them. There's some pivot point. Across the pivot, all of the seen stuff
//reappears, but in backwards order. Allowed a buffer, this can be done in n time.
//The pivot point is always in the middle

#include <stack>
#include "listHelpers.h"
using namespace std;

bool IsPalindrome( node* head )
{
    node * n = head;
    //First find the length to know the reflection point.
    int len = 0;
    while( n != NULL )
    {
        ++len;
        n = n->next;
    }
    if(len == 0 )
        return true;

    stack<int> seen;
    n = head;
    int i = 0;//this is to know when to stop stacking
    while( i < len/2 )
    {
        seen.push(n->data);
        ++i;
        n = n->next;
    }
    if( len % 2 == 1 )
    {
        n = n->next;//skip the middle one if odd. It can be anything
    }
    while ( n != NULL )
    {
        if( seen.top() != n->data )
            return false;
        seen.pop();
        n = n->next;
    }
    return true;
}

#include <iostream>
int main()
{
    //make an even length list
    node * head1 = new node;
    head1->data = 0;
    node * tail1 = head1;
    for( int i = 1; i < 3; ++i )
    {
        tail1->next = new node;
        tail1 = tail1->next;
        tail1->data = i % 5;
    }
    for( int i = 2; i >= 0; --i )
    {
        tail1->next = new node;
        tail1 = tail1->next;
        tail1->data = i % 5;
    }
    tail1->next = NULL;
    printList( head1 );
    cout << (IsPalindrome( head1 ) == true) << endl;

    //make it an odd length list by deleting one of the middle nodes.
    node * n = head1->next->next;
    node * deleteMe = n->next;
    n->next = deleteMe->next;
    delete deleteMe;
    printList( head1 );
    cout << (IsPalindrome( head1 ) == true) << endl;

    //make it no longer a palindrome by tacking some shit on the end.
    tail1->next = new node;
    tail1 = tail1->next;
    tail1->data = 8;
    tail1->next = NULL;
    printList( head1 );
    cout << (IsPalindrome( head1 ) == false) << endl;
    getchar();
    return 0;
}