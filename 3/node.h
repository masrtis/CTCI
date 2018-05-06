#ifndef node_h
#define node_h
template < class D >
class Node
{
public:
    D data;
    Node< D > *next;
    Node() { next = NULL; }
    Node( D inData )
    {
        next = NULL;
        data = inData;
    }
};

template < class D >
struct ListExtrema
{
    Node< D > *head;
    Node< D > *tail;
};

template < class D >
ListExtrema< D > CopyNodes( Node< D > *in )
{
    ListExtrema< D > out;
    if( in == NULL )
    {
        out.head = NULL;
        out.tail = NULL;
        return out;
    }
    Node< D > *head = new Node< D >( in->data );
    in = in->next;
    Node< D > *tail = head;

    while( in != NULL )
    {
        tail->next = new Node< D >( in->data );
        tail = tail->next;
        in = in->next;
    }
    tail->next = NULL;

    out.head = head;
    out.tail = tail;
    return out;
}

template < class D >
void DeleteNodes( Node< D > *n )
{
    Node< D > *deleteMe;
    while( n != NULL )
    {
        deleteMe = n;
        n = n->next;
        delete deleteMe;
    }
}

#endif