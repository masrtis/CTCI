// Q: Implement a queue using two stacks.

// A: so I'm going to have two stacks inside this queue class. For a queue, I
// need access to the oldest elements. A stack just gives me the most recent one.
// So I'm going to have to turn the stack upside down to get at the older stuff.
// There will be an "antiStack" with the old stuff at the top I'll make a member
// function called "flip", which inverts one stack onto a second. I will only
// flip when necessary.

#include "stack.h"
using namespace std;

template < class dType >
class MyQueue
{
private:
    custom::Stack< dType > m_stack;
    custom::Stack< dType > m_antiStack;

    void flip( custom::Stack< dType > &s1, custom::Stack< dType > &s2 )
    {
        // flip stack 1 over onto stack 2, leaving stack 1 empty
        while( !s1.empty() )
        {
            s2.push( s1.top() );
            s1.pop();
        }
    }

public:
    size_t size()
    {
        return m_stack.size() | m_antiStack.size(); // one of these boys is
                                                    // empty
    }

    // new stuff needs to go with recent stuff, in the uninverted stack
    void push_back( dType data )
    {
        if( m_stack.empty() )
            flip( m_antiStack, m_stack );
        m_stack.push( data );
    }

    // need to get this from the inverted stack
    dType front()
    {
        if( m_antiStack.empty() )
            flip( m_stack, m_antiStack );
        return m_antiStack.top();
    }

    // same
    void pop_front()
    {
        if( m_antiStack.empty() )
            flip( m_stack, m_antiStack );
        m_antiStack.pop();
    }

    bool empty() { return size() == 0; }
};

#include <iostream>
int main()
{
    MyQueue< int > q;
    cout << ( q.empty() ) << endl;
    q.push_back( 0 );
    cout << ( q.size() == 1 ) << endl;
    q.push_back( 1 );
    q.push_back( 2 );
    cout << ( q.front() == 0 ) << endl;
    q.pop_front();
    cout << ( q.front() == 1 ) << endl;

    getchar();
    return 0;
}