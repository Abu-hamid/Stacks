#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NextSmaller(vector<int> arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while (s.top() >= curr)
        {

            s.pop();
        }

        // ans is the top of the stack;

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}
int main()
{

    return 0;
}