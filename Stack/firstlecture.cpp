#include <iostream>
#include <stack>
using namespace std;

class Stack
{
    // data members
public:
    int *arr;
    int top;
    int size;

    //    behaviour
    Stack(int size)
    {
        this->size = size;
        
        /* Array memory allocate*/
        arr = new int[size];
        top = -1;
        cout<<"Size of Array: "<<size<<endl;
    }

    // push element
    void push(int element)
    {

        // atleast one space is present
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
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
            cout << "Stack Underflow" << endl;
        }
    }

    int peak()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    /*
    // creation of stack
    stack<int> s;

    // push operation
    s.push(3);
    s.push(4);

    // pop operation
    s.pop();

    cout << "Printing top element : " << s.top() << endl;

    if (s.empty())
    {
        cout << "Stack is Empty " << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }

    cout << "Size of Stack is : " << s.size() << endl;
    */

    Stack st(5);
    st.push(22);
    st.push(34);
    st.push(24);
    st.push(12);
    st.push(5);
    st.push(10);

    cout << "top : " << st.peak() << endl;
    // st.pop();
    // cout << "top : " << st.peak() << endl;
    // st.pop();
    // cout << "top : " << st.peak() << endl;
    // st.pop();
    // cout << "top : " << st.peak() << endl;
    


    if(st.isEmpty()){
        cout<<"Stack Is Empty "<<endl;
    }
    else{
        cout<<"Stack is not Empty "<<endl;
    }
}