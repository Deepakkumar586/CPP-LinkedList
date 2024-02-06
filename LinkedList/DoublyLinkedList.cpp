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

    // destructure
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next= NULL;
        }
        cout<<"memory free for node with data  "<<val<<endl;
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

void insertAtHead(Node *&tail, Node *&head, int d)
{

    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // insert node at Start
    if (position == 1)
    {
        insertAtHead(tail,head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    /* insert node at last*/
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // creating  a new Node in middle
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
/* --------->>>>>>> DELETION START ------------>>>>>>>>>*/
void deleteNode(int position, Node *&head)
{

    // Delete Start Node
    if (position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next  =NULL;

        // Memory Free
        delete temp;

    }
    else
    {
        // delete any middleNode Or Last Node
        Node *current = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = current;
            current = current->next;
            cnt++;
        }

        current->prev = NULL;
        prev->next = current->next;
        current->next = NULL;
        delete current;
        // if (prev->next == NULL)
        // {
        //     tail = prev;
        // }
    }
}


int main()
{

    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(tail,head, 11);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    // cout << getLength(head) << endl;

    insertAtHead(tail,head, 15);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    // cout << getLength(head) << endl;

    insertAtHead(tail,head, 19);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    // cout << getLength(head) << endl;

    insertAtTail(tail, head, 26);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtPosition(head, tail, 2, 30);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertAtPosition(head, tail, 1, 31);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtPosition(head, tail, 7, 100);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

     insertAtPosition(head, tail, 8, 101);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


     insertAtPosition(head, tail, 9, 102);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    deleteNode(9,head);
    print(head);

    return 0;
}