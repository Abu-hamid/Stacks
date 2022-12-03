#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{

    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {

        if (M[a][b] == 1)
            return true;

        else
            return false;
    }

public:
    int celebrity(vector<vector<int>> &M, int n)
    {

        stack<int> s;

        // push all the element into the stack ;

        for (int i = 0; i < n; i++)
        {

            s.push(i);
        }

        // step 2; get two element and compare it;

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
            {

                s.push(b);
            }

            else
            {

                s.push(a);
            }
        }

        int candidate = 0;
        //  step 3 ; single element in the stack is potential celeb;
        // so verify it ;

        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {

            if (M[candidate][i] == 0)
                zeroCount++;
        }

        // all zero;

        if (zeroCount != n)
            return -1;

        // coloumn check;

        int oneCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][candidate] == 1)
                oneCount++;
        }
        // all zero;
        if (oneCount != n - 1)
            return -1;

        return candidate;
    }
};
int main()
{

    return 0;
}