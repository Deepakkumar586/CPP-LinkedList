#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
        // cout<<"Data : "<<this->data<<endl;
        // cout<<"Prev: "<<this->prev<<endl;
        // cout<<"Next : "<<this->next<<endl;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// length of LinkedList
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node*&head,int  d){
    Node *temp = new Node(d);
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;

    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head,11);
    print(head);


    return 0;
}