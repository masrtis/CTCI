// Q: implement a data structure "SetOfStacks" that prevents any one stack from
// getting too tall. So once the stack maxes out, it starts with a new one
// internally. this outer structure should have the regular stack interface --
// push, pop, top, empty, and should behave identically to a stack. Q: bonus,
// write a "pop_from" function to pop from a given stack instead of the top of
// the whole thing.

// A: The bonus indexing part prevents me from implementing this as a stack of
// stacks. The outer structure will have to be an array or vector or some kind.

#include "stack.h"
#include <stdexcept>
#include <vector>
using namespace std;

template < class dType >
class SetOfStacks
{
private:
    size_t m_size;
    size_t m_maxHeight;
    size_t m_stackCount;
    vector< custom::Stack< dType > > m_set;
    SetOfStacks() {}

public:
    SetOfStacks( size_t height )
    {
        m_maxHeight = height;
        m_size = 0;
        m_stackCount = 0;
    }

    void push( dType data )
    {
        ++m_size;
        // if there are no stacks in the vec, create one, and put the data in
        // there
        if( m_set.empty() )
        {
            m_set.emplace_back( custom::Stack< dType >( data ) );
            ++m_stackCount;
            return;
        }
        // if there is some backmost stack not full, put the data in there
        if( m_set.back().size() < m_maxHeight )
        {
            m_set.back().push( data );
        }
        // the backmost stack is full, create a new one and place the data
        else
        {
            m_set.emplace_back( custom::Stack< dType >( data ) );
            ++m_stackCount;
        }
    }

    dType top()
    {
        if( m_set.empty() )
        {
            throw range_error( "" );
        }

        return m_set.back().top();
    }

    void pop()
    {
        if( m_set.empty() )
            throw range_error( "" );
        --m_size;
        // pop from backmost stack
        m_set.back().pop();
        // get rid of that stack if it's done
        if( m_set.back().empty() )
        {
            m_set.pop_back();
            --m_stackCount;
        }
    }

    size_t size() { return m_size; }

    bool empty() { return m_size == 0; }

    size_t stack_count() { return m_stackCount; }
};

#include <iostream>
int main()
{
    // create new set. set max height to 4
    SetOfStacks< int > aSet( 4 );

    // expect no stacks
    cout << ( aSet.stack_count() == 0 ) << endl;

    aSet.push( 0 );
    aSet.push( 1 );
    aSet.push( 2 );
    aSet.push( 3 );

    // expect 1 stack
    cout << ( aSet.stack_count() == 1 ) << endl;

    cout << ( aSet.top() == 3 ) << endl;

    aSet.push( 4 );
    cout << ( aSet.stack_count() == 2 ) << endl;

    cout << ( aSet.top() == 4 ) << endl;
    cout << ( aSet.size() == 5 ) << endl;

    aSet.push( 5 );

    aSet.pop();
    aSet.pop();
    aSet.pop();
    cout << ( aSet.top() == 2 ) << endl;
    getchar();
    return 0;
}