//Implement a basic stack
#include <stdexcept>
#include "node.h"


namespace custom
{
template <class D>
class Stack
{
private:
    Node<D> * head;
public:
    Stack()
    {
        head = NULL;
    }

    Stack(D data)
    {
        head = new Node<D>;
        head->data = data;
    }

    ~Stack()
    {
        DeleteNodes(head);
    }

    void push(D data)
    {
        Node<D> * oldHead = head;
        head = new Node<D>(data);
        head->next = oldHead;
    }

    //copy constructor
    Stack(const Stack<D>& in)
    {
        head = CopyNodes(in.head).head;
    }

    //copy assignment
    Stack<D>& operator=(const Stack<D>& rhs)
    {
        DeleteNodes(head);
        head = CopyNodes(rhs.head).head;
    }

    D top()
    {
        if(empty())
            throw std::length_error("stack is empty");
        return head->data;
    }

    void pop()
    {
        if(empty())
            throw std::length_error("stack is empty");
        Node<D> * oldHead = head;
        head = oldHead->next;
        delete head;
    }

    bool empty()
    {
        return head == NULL;
    }
};

} // namespace