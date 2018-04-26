class node
{
public:
    int data;
    node * next;
};

#include <iostream>
void printList( node * head )
{
    node * current = head;
    std::cout << current->data;
    while( current->next != NULL )
    {
        current = current->next;
        std::cout << "->" << current->data;
    }
    std::cout << std::endl;
}

void DeleteNext( node * n )
{
    if( n == NULL || n->next == NULL )
        return;
    node * deleteMe = n->next;
    n->next = deleteMe->next;

    free( deleteMe );
}