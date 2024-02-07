#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructur
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{
    // assuming that the element is present in the list

    // For empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        // Circular
        newNode->next = newNode;
    }
    else
    {
        // Now List Is Not Empty
        //  assuming element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        //  element found-->> curr node is present element wala node

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

// delete Node
void deleteNode(Node *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty Please Check List" << endl;
    }
    else
    {
        // non-empty

        // assuming that "value" is present in yhe linked List
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        // found---> then delete value
        prev->next = curr->next;

        // case 1 : if only one node are exist
        if (curr == prev)
        {
            tail = NULL;
        }

        // CAse- 2 : if Two or more Than node are exist then :
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 4, 2);
    print(tail);
    insertNode(tail, 2, 3);
    print(tail);

    insertNode(tail, 2, 3);
    print(tail);

    insertNode(tail, 3, 6);
    print(tail);

    insertNode(tail, 6, 8);
    print(tail);

    insertNode(tail, 2, 1);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    insertNode(tail, 4, 5);
    print(tail);

    deleteNode(tail, 2);
    print(tail);
    return 0;
}