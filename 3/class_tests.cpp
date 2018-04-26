#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;
int main()
{
    cout << "STACK CHECKS" << endl;
    //does the default constructor work?
    custom::Stack<int> emptyStack;
    cout << (emptyStack.empty() == true ) << endl;

    //other constructor and member functions?
    custom::Stack<int> stack(0);
    cout << ( stack.empty() == false ) << endl;
    cout << ( stack.top() == 0 ) << endl;
    stack.push(1);
    cout << ( stack.top() == 1 ) << endl;
    stack.push(2);
    stack.pop();
    stack.pop();
    stack.pop();
    cout << (emptyStack.empty() == true ) << endl;

    try
    {
        stack.pop();
        cout << 0 << endl;
    }
    catch(length_error& error )
    {
        cout << 1 << endl;
    }

    cout << "\n\nQUEUE CHECKS\n";

    custom::Queue<int> queue;
    cout << (queue.empty() == true) << endl;
    queue.push_back(0);
    cout << (queue.empty() == false) << endl;
    cout << (queue.front() == 0) << endl;
    queue.push_back(1);
    cout << (queue.front() == 0) << endl;
    queue.pop();
    cout << (queue.front() == 1) << endl;
    queue.pop();
    cout << (queue.empty() == true) << endl;

    try
    {
        queue.front();
        cout << 0 << endl;
    }
    catch(length_error& e)
    {
        cout << 1 << endl;
    }

    try
    {
        queue.pop();
        cout << 0 << endl;
    }
    catch(length_error& e)
    {
        cout << 1 << endl;
    }

    getchar();
    return 0;
}