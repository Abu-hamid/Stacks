#include <iostream>
#include <stack>
using namespace std;


// important ques. ;

bool RedundantBracis(string &s)
{

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            st.push(ch);
        }
        else
        {

            // ch ya to closing ho ya fir lower casse later;

            if (ch == ')')
            {
                bool isRedundent = true;
                while (st.top() != '(')
                {

                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {

                        isRedundent = false;
                    }
                    st.pop();
                }

                if (isRedundent == true)
                    return true;

                st.pop();
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}