#include <iostream>
#include <stack>
using namespace std;

// implimentation of stack without using of STL ;

class stack
{

public:
    // data
    int *arr;
    int top;
    int size;

    // behaviour;
    stack(int data)
    {

        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {

            top++;
            arr[top] = element;
        }

        else
        {
            cout << " space is not enough to store the any more data" << endl;
        }
    }

    int peek()
    {

        if (top >= 0)
        {

            return arr[top];
        }
        else
        {

            cout << "stack is empty" << endl;
            return -1;
        }
    }
    void pop()
    {

        if (top >= 0)
        {

            top--;
        }

        else
        {

            cout << "stack underflow" << endl;
        }
    }
    bool isempty()
    {
        if (top == -1)
            return true;

        else
            return false;
    }
};

int main()
{

    stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    st.pop();
    st.pop();
    st.pop();

    while (!st.isempty())
    {
        cout << st.peek() << " ";
    }

    return 0;
}