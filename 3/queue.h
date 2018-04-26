//implement a basic queue

//quene is FIFO. I will constantly be deleting the head and adding onto the tail
//I'll name the push function "push_back" to be consistent with the stack. I was going back and forth between that and "insert"
#include <stdexcept>
#include "node.h"

namespace custom
{
template <class D>
class Queue
{
private:
    Node<D> * head;
    Node<D> * tail;
public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    Queue(D data)
    {
        head = new Node<D>(data);
        tail = head;
    }
    bool empty()
    {
        return head == NULL;
    }
    D front()
    {
        if(empty())
            throw std::length_error("queue is empty");
        return head->data;
    }
    void push_back(D data)
    {
        if(head == NULL)
        {
            head = new Node<D>(data);
            tail = head;
        }
        else
        {
            Node<D> * newTail = new Node<D>(data);
            tail->next = newTail;
            tail = newTail;
        }
    }
    void pop()
    {
        if(empty())
            throw std::length_error("queue is empty");
        Node<D> * oldHead = head;
        head = head->next;
        delete oldHead;
        //in the size=1 case, dangling tail is actually OK, because push_back checks if the HEAD is NULL and resets the tail
    }
};
}