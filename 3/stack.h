// Implement a basic stack

#ifndef stack_h
#define stack_h

#include "node.h"
#include <stdexcept>

namespace custom
{
template < class D >
class Stack
{
private:
    Node< D > *m_head;
    size_t m_size;

public:
    Stack()
    {
        m_head = NULL;
        m_size = 0;
    }

    Stack( D data )
    {
        m_head = new Node< D >;
        m_head->data = data;
        m_size = 1;
    }

    ~Stack() { DeleteNodes( m_head ); }

    void push( D data )
    {
        Node< D > *oldHead = m_head;
        m_head = new Node< D >( data );
        m_head->next = oldHead;
        ++m_size;
    }

    // copy constructor
    Stack( const Stack< D > &in )
    {
        m_head = CopyNodes( in.m_head ).head;
        m_size = in.m_size;
    }

    // copy assignment
    Stack< D > &operator=( const Stack< D > &rhs )
    {
        DeleteNodes( m_head );
        m_head = CopyNodes( rhs.m_head ).head;
        m_size = rhs.m_size;
    }

    D top()
    {
        if( empty() )
            throw std::length_error( "stack is empty" );
        return m_head->data;
    }

    void pop()
    {
        if( empty() )
            throw std::length_error( "stack is empty" );
        Node< D > *oldHead = m_head;
        m_head = oldHead->next;
        delete oldHead;
        --m_size;
    }

    size_t size() { return m_size; }

    bool empty() { return m_size == 0; }
};

} // namespace custom

#endif // include guard