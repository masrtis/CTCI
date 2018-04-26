//Write code to remove duplicates from an unsorted singly linked list
//A) Temp buffer allowed


#include "listHelpers.h"
#include <unordered_map>
#include <forward_list>

using namespace std;

void DedupeList( forward_list< int >& input )
{
    unordered_map< int, bool > seen;

    //set up iterators
    forward_list< int >::iterator follow = input.begin();
    forward_list< int >::iterator vanguard = follow;
    ++vanguard;
    forward_list< int >::iterator end = input.end();

    if( follow == end )
        return;

    seen[*follow] = true;

    while( vanguard != end )
    {
        if( seen[*vanguard] )
        {
            //Delete the node
            vanguard = input.erase_after( follow );
        }
        else
        {
            //Mark it as seen
            seen[*vanguard] = true;

            //Advance
            ++vanguard;
            ++follow;
        }
    }
}


int main()
{
    forward_list<int> testList = {6, 3, 1, 7, 10, 10, 7, 1, 1, 1};
    //print the list
    for( auto& element : testList )
        cout << element << ' ';
    cout << endl;

    DedupeList( testList );

    for( auto& element : testList )
        cout << element << ' ';
    cout << endl;

    getchar();
    return 0;
}