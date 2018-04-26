/* Provided with a method IsSubstring, and given strings s1 and s2, write a function to check if s2 is a rotation of s1
  using only 1 function call to IsSubstring */

#include <string>
using namespace std;

//This can be done better using modular indexing, but the question has its own constraints.
//One solution is to double one of the strings and then check if the other is a substring.
//This will take a little bit of memory, but is pretty easy

bool IsRotation( const string& s2, const string& s1 )
{
    if( s1.size() != s2.size() )
        return false;
    return IsSubstring( s2, s1 + s1 );
}