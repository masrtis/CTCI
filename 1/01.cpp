/* Write a funciton to determine if all characters in a string are unique. Redo without using additional data structures */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool AllUnique(const string & s)
{
    vector< bool > charCount(255, 0); //init necessary for POD?

    for( size_t i = 0; i < s.length(); ++i )
    {
        if( charCount[ s[i] ] == 1 )
            return false;
        charCount[ s[i] ] = 1;
    }
    return true;
}

// Using cpp11
bool AllUnique11(const string & s)
{
    vector< bool > charCount(255, 0);

    for( const char & c : s )
    {
        if( charCount[ c ] == 1 )
            return false;
        charCount[ c ] = 1;
    }
    return true;
}

//Write such a function that doesn't require additional data structures
#include <algorithm>
bool AllUniqueNoDS(string s)
{
    if( s.length() == 0)
        return true;

    sort( s.begin(), s.end() );

    for( size_t i = 0; i < s.length()-1; ++i)
    {
        if(s[i] == s[i+1])
            return false;
    }
    return true;
}

void test(bool b)
{
    if(b)
        cout << "pass" << endl;
    else
        cout << "fail" << endl;
    return;
}

int main()
{
    string s1("asdfkl;");
    string s2("asdflkjsl;kj");
    string s3("");

    test( AllUnique11(s1) );
    test( !AllUnique11(s2) );
    test( AllUnique11(s3) );

    getchar();
    return 0;
}