#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // create a queue
    queue<int> q;

    q.push(1);
    cout << "front of Queue: " << q.front() << endl;
    cout << "back of Queue: " << q.back() << endl;
    q.push(7);
    q.push(5);
    cout << "front of Queue: " << q.front() << endl;
    cout << "back of Queue: " << q.back() << endl;

    q.push(8);
    q.push(4);
    q.push(3);
    cout << "front of Queue: " << q.front() << endl;

    cout << "Size of Queue is : " << q.size() << endl;
    q.pop();
    cout << "Size of Queue is : " << q.size() << endl;

    if (q.empty())
    {
        cout << "Queue is Empty :" << endl;
    }
    else
    {
        cout << "Queue is Not Empty : " << endl;
    }
}