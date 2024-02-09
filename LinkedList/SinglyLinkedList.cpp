/* Implementation of Linked List*/

// #include <iostream>
// using namespace std;

// class Node
// {

// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// int main()
// {
//     Node *node1 = new Node(10);
//     cout << node1->data << endl;
//     cout << node1->next << endl;

//     return 0;
// }

/* How to Insert New nOde  as well as Delete Node*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;

        // Memory Free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is Free For Node With Data " << value << endl;
    }
};

// &head means---> We change original value of Linked List
void insertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
/*Inserr Node in Middle*/
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    // creating a new Node
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// how to traverse linked list
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

/* --------->>>>>>> DELETION START ------------>>>>>>>>>*/
void deleteNode(int position, Node *&head, Node *&tail)
{

    // Delete Start Node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
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

        prev->next = current->next;

        current->next = NULL;

        delete current;
        if (prev->next == NULL)
        {
            tail = prev;
        }
    }
}

/*        LENGTH OF LINKED LIST       */
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
// detect Loop
bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present Element :" << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// floyd Detect Loop
Node *floydLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Present Element :" << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

// starting Node of Loop
Node *getStartingNode(Node *head)
{
    // if list is empty
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = floydLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove cycle
void removeCycle(Node *head)
{

    // empty list
    if (head == NULL)
    {
        return;
    }

    Node *startofLoop = getStartingNode(head);
    Node *temp = startofLoop;
    while (temp->next != startofLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    // Created New Node
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    insertAtTail(tail, 12);
    // print(head);

    insertAtTail(tail, 15);
    // print(head);

    insertAtTail(tail, 22);

    // detect loop
    // tail->next = head->next;
    // if(detectLoop(head)){
    //     cout<<"cycle is present"<<endl;
    // }
    // else{
    //     cout<<"cycle is not present"<<endl;
    // }

    // use floyd cycle detection Alogorithm
    tail->next = head->next;
    if (floydLoop(head) != NULL)
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    // Start Point Of Node FInd
    Node *startPoint = getStartingNode(head);
    cout << "Starting Node at : " << startPoint->data << endl;

    // Remove Loop/Cycle
    removeCycle(head);
    print(head);

    // insertAtPosition(head, tail, 4, 22);
    // print(head);

    /*
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    cout << getLength(head) << endl;*/

    /*deleteNode(2, head, tail);
    // print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    cout << getLength(head) << endl;*/

    return 0;
}