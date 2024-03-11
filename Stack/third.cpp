#include <iostream>
#include <stack>
using namespace std;
int main(){


    
    stack<int> s;
    s.push(2);
    s.push(1);
    s.push(3);
    s.push(8);
    cout<<"stack is :"<<s.top()<<endl;


    while (!s.empty()) {
        int val = s.top();
        cout << "Popped element: " << val << endl;
              s.pop();
    }
  
}