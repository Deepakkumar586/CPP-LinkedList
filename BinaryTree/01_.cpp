#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// first way  build tree -simple way through recursion
node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
};

// Inorder Traverse -LNR

void inorderTraversal(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " " << endl;
    inorderTraversal(root->right);
}
void preOrderTraversal(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " " << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " " << endl;
}

// second way build tree level order through
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            node *left = new node(leftData);
            temp->left = left;
            q.push(left);
        }

        cout << "Enter right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            node *right = new node(rightData);
            temp->right = right;
            q.push(right);
        }
    }
}

int main()
{

    node *root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    /*

    // creating a Tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    // for inorder traversal
    cout << "Inorder traversal :" << endl;
    inorderTraversal(root);

    // for preorder traversal
    cout << "Preorder traversal :" << endl;
    preOrderTraversal(root);


    // for postorder traversal
    cout << "Postorder traversal :" << endl;
    postOrderTraversal(root);

    return 0;
    */
}