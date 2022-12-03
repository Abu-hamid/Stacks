#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerelement(int *arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is the top of the stack;
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerelement(int *arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is the top of the stack;
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestArearectangle(int *heights, int n)
{

    // int n = heights.size();

    vector<int> next(n);
    next = nextSmallerelement(heights, n);

    vector<int> prev;
    prev = prevSmallerelement(heights, n);

    int area = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int maxArea = l * b;

        area = max(area, maxArea);
    }
    return area;
}

int maxArea(int M[100][100], int n, int m)
{

    //  compute the row 1 area;
    int area = largestArearectangle(M[0], m);


// for rest row area ;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            // update the row by adding prev row value with current row value;

            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];

            else
                M[i][j] = 0;
        }

        // entire row is updated at this point;

        area = max(area, largestArearectangle(M[i], m));
    }
    return area;
}
int main()
{

    return 0;
}