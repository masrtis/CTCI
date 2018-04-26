// Given a string, write a function to check if it's a permutation of a palindrome.
// The words need not be real English.

#include <vector>
#include <string>

using namespace std; bool IsPalindromePermutation( const string & s )
{
    /* a palindrome is left-right symmetric. Therefore, either every character
       will appear an even number of times, or ONLY ONE character will be
       allowed to appear an odd number of times (if there is an odd number
       of characters in the string) */
    vector<unsigned> counts( 255, 0 );

    for( const char c : s )
        counts[c]++;

    bool oddEncountered = false;

    for( unsigned count : counts )
    {
        if( count % 2 == 1 )
        {
            if( oddEncountered )
                return false;
            oddEncountered = true;
        }
    }
    return true;
}

#include <iostream>
int main()
{
    cout << IsPalindromePermutation( string("sadfdsaf") ) << endl;
    getchar();
    return 0;
}