// Define only 3 string edits -- char insertion, char deletion, and char replacement. Write a function to determine if two strings are within 1 edit of each other.
#include <string>

using namespace std;

bool WithinAnEdit( const string & s1, const string & s2 )
{
    size_t L1 = s1.length();
    size_t L2 = s2.length();

    bool editFound = false;

    for( size_t left = 0, right = 0; left < L1 || right < L2; )
    {
        if( s1[left] != s2[right] )
        {
            if( editFound )
                return false;
            editFound = true;

            if( L1 <= L2 )
                ++right;
            if( L2 <= L1 )
                ++left;
        }
        else
        {
            ++left;
            ++right;
        }
    }
    return true;
}

#include <iostream>
int main()
{
    string pale("pale");
    string pales("pales");
    string ple("ple");
    string bale("bale");
    string bake("bake");


    cout << WithinAnEdit( pale, ple ) << endl;
    cout << WithinAnEdit( pales, pale ) << endl;
    cout << WithinAnEdit( pale, bale ) << endl;
    cout << WithinAnEdit( pale, bake ) << endl;
    getchar();
    return 0;
}