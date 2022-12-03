#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//  ***** Important question;

class Nstack
{

    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    Nstack(int N, int S)
    {

        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialise the top;

        for (int i = 0; i < n; i++)
        {

            top[i] = -1;
        }

        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;

            // put last value will be -1;

            next[s - 1] = -1;
        }

        // intisialise the freeSpot

        freespot = 0;
    }

    bool push(int x, int n)
    {

        // check for overflow;

        if (freespot == -1)
            return false;

        // find index;

        int index = freespot;

        // update freespot;

        freespot = next[index];

        // insert element in the array;

        arr[index] = x;

        // update next ;

        next[index] = top[n - 1];

        // update top;

        top[n - 1] = index;

        return true;
    }

    // pop  the top element from the Nth stack return -1 if not present ;

    int pop(int m)
    {

        // check underflow condition;

        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{

    return 0;
}