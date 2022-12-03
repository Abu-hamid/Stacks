#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputstack, int count, int size)
{

    // base case;

    if (count == size / 2)
    {

        inputstack.pop();
        return;
    }

// move out of the stack on the top element ;
    int num = inputstack.top();
    inputstack.pop();

    // recursive call ;

    solve(inputstack, count + 1, size);
    
    // put the value again;
    inputstack.push(num);
}

void deleteMid(stack<int> &inputstack, int n)
{

    int count = 0;

    solve(inputstack, count, n);
}

int main()
{

    return 0;
}