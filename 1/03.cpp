// Given a character array that has "sufficient extra space" at the end, and the "true length" of that string, replace all spaces with "%20"

void ReplaceSpaces( char * s, int L )
{
    int spaceCount = 0;

    for( size_t i = 0; i < L; ++i )
    {
        if( s[i] == ' ' )
            ++spaceCount;
    }

    size_t leftPlace = L - 1;
    size_t rightPlace = leftPlace + (2*spaceCount);

    for( size_t i = 0; i < spaceCount; )
    {
        if( s[leftPlace] == ' ')
        {
            s[rightPlace--] = '0';
            s[rightPlace--] = '2';
            s[rightPlace--] = '%';
            ++i;
        }
        else
        {
            s[rightPlace--] = s[leftPlace];
        }
        leftPlace--;
    }
}

#include <iostream>
using namespace std;
int main()
{
    char inString[] = "one two three four*************************";
    ReplaceSpaces( inString, 18 );
    cout << inString << endl;
    getchar();
    return 0;
}