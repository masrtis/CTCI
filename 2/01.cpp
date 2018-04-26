//Write code to remove duplicates from an unsorted singly linked list
//A) Temp buffer allowed


#include "listHelpers.h"
#include <unordered_map>

using namespace std;

void DedupeList(node * head)
{
    unordered_map< int, bool > seen;
    seen[head->data] = true;

    node * prev = head;
    node * current = head->next;

    while( current != NULL )
    {
        if( seen[current->data] )
        {
            //Delete the node
            prev->next = current->next;
            free( current );
            current = prev->next;
        }
        else
        {
            //Mark it as seen
            seen[current->data] = true;

            //Advance to the next one
            prev = prev->next;
            current = current->next;
        }
    }
}

//B) no temp buffer allowed. I'm assuming here that I'm not allowed to sort the list -- in while case this will be some order n^2 bullshit
void DedupeList_NoBuffer( node * head )
{
    node * stander = head;
    while( stander != NULL )
    {
        node * runnerPrev = stander;
        node * runner = stander->next;

        while( runner != NULL )
        {
            if( runner->data == stander->data )
            {
                DeleteNext( runnerPrev );
                runner = runnerPrev->next;
            }
            else
            {
                runner = runner->next;
                runnerPrev = runnerPrev->next;
            }
        }
        stander = stander->next;
    }
}

int main()
{
    node * head = new node;
    head->data = 0;
    node * tail = head;
    for( int i = 1; i < 15; ++i )
    {
        tail->next = new node;
        tail = tail->next;
        tail->data = i % 4;
    }
    tail->next = NULL;

    printList( head );
    DedupeList( head );
    // DedupeList_NoBuffer( head );
    printList( head );

    getchar();
    return 0;
}