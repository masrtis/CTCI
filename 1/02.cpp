// Given two strings, write a method to determine if one is a permutation of the other.
#include <vector>
#include <string>

using namespace std;

bool IsPermutation( const string & s1, const string & s2 )
{
    if( s1.length() != s2.length() )
        return false;

    vector<unsigned> counts1( 255, 0 );
    vector<unsigned> counts2( 255, 0 );

    for( size_t i = 0; i < s1.length(); ++i)
    {
        counts1[s1[i]] += 1;
        counts2[s2[i]] += 1;
    }
    return counts1 == counts2;
}

#include <iostream>
int main()
{
    string s1("qwertyuiop1234567890");
    string s2("poiuytrewq0987654321");
    string s3("poiuytreabcd87654321");
    string s4("");
    cout << IsPermutation( s1, s2 ) << endl;
    cout << IsPermutation( s1, s3 ) << endl;
    cout << IsPermutation( s4, s3 ) << endl;
    cout << IsPermutation( s4, s4 ) << endl;
    getchar();
    return 0;
}