// Q: Write a function to sort a stack such that the smallest elements are at
// the top. As far as temporary data structures go, only another stack is
// allowed.

// A: I'm pretty sure I can only compare adjacent elements, which makes this a
// modified bubble sort. O(n) in space. O(n^2) in time I'll have two stacks --
// the original stack called "left,"" and another one, called "right", which will
// be inverted -- biggest at top. For the first stab at the solution I'll have
// two functions, shake right, and shake left. Shake right is as follows. Pop one
// guy from left. Put in temp var. Peek next. If next is bigger, push it to the
// right stack and continue like that. If next is smaller, push temp. Set temp to
// next.

#include "stack.h"
using namespace std;

template < class DT >
bool ShakeRight( custom::Stack< DT > &left, custom::Stack< DT > &right )
{
    bool stillSorting = false;

    DT temp = left.top();
    left.pop();

    while( !left.empty() )
    {
        if( left.top() < temp ) // place the smaller thing down on the right
        {
            right.push( left.top() );
            stillSorting = true;
        }
        else
        {
            right.push( temp );
            temp = left.top();
        }
        left.pop();
    }
    right.push( temp );
    return stillSorting;
}

// I'm sure there's a clever way to undupe this code, but I certainly couldn't
// make it work without consulting reference.
template < class DT >
bool ShakeLeft( custom::Stack< DT > &left, custom::Stack< DT > &right )
{
    bool stillSorting = false;

    DT temp = right.top();
    right.pop();

    while( !right.empty() )
    {
        if( right.top() > temp )
        {
            left.push( right.top() ); // plop large things down first
            stillSorting = true;
        }
        else
        {
            left.push( temp );
            temp = right.top();
        }
        right.pop();
    }
    left.push( temp );
    return stillSorting;
}

template < class DT >
void Sort( custom::Stack< DT > &in )
{
    if( in.size() < 2 )
        return; // This saves me checks in the shakers

    custom::Stack< DT > temp;

    while( ShakeRight( in, temp ) && ShakeLeft( in, temp ) )
        continue;

    if( in.empty() )
        ShakeLeft( in, temp );
}

#include <iostream>
int main()
{
    custom::Stack< int > s;
    s.push( 20 );
    s.push( 1 );
    s.push( 4 );
    s.push( 10 );
    s.push( 0 );
    s.push( 35 );
    s.push( 1 );
    s.push( 12 );

    Sort( s );
    while( !s.empty() )
    {
        cout << s.top() << ' ';
        s.pop();
    }
    getchar();
    return 0;
}

// After consulting the book, it turns out they were allowing as many stacks as
// you want. They did this with 3 total.
