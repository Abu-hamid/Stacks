#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> & s , int x){

    // base case;

    if(s.empty()){

        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call ;

    solve(s , x);

    s.push(num);
}

stack<int> insetAtBottom(stack<int> & mystack , int x){

    solve(mystack , x);

    return mystack;
}

int main(){

return 0;
}