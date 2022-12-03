#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (st.empty())
        {
            st.push({price, 1});
            return 1;
        }
        else
        {
            int ans = 1;
            while (!st.empty() && st.top().first <= price)
            {
                auto x = st.top();
                st.pop();
                int first = x.first;
                int second = x.second;
                ans += second;
            }
            st.push({price, ans});
            return ans;
        }
        return 0;
    }
};

int main()
{

    return 0;
}