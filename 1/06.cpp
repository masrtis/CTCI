// Write a function that does wonky string compression, such that
// aaabcccccaaa becomes a3b1c5a3. Return the shorter of the original and the compressed.

#include <string>

using namespace std;

string CompressString( const string& in )
{
    size_t inLen = in.length();
    if( inLen == 0 )
        return in;
    string out;
    char currentChar = in[0];
    size_t count = 0;

    for( size_t i = 0; i < inLen ; ++i)
    {
        if( in[i] == currentChar )
            ++count;
        if( in[i] != currentChar || i == inLen - 1 )
        {
            out += currentChar; // Is this shit quadratic or not?
            out += to_string( count );
            currentChar = in[i];
            count = 1;
        }
    }
    return out.length() < inLen ? out : in;
}

#include <iostream>
int main()
{
    cout << CompressString( string("aaabcccccaaa") );
    getchar();
    return 0;
}