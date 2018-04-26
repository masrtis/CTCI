#ifndef node_h
#define node_h
template <class D>
class Node
{
public:
    D data;
    Node<D> * next;
    Node()
    {
        next = NULL;
    }
    Node(D inData)
    {
        next = NULL;
        data = inData;
    }
};
#endif