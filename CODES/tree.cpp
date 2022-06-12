#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    int priority;
    Node *left;
    Node *right;
};

Node *CreateNode(int key, int priority)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *InsertNode(Node *root, int key, int priority)
{
    if (root == NULL)
    {
        root = CreateNode(key, priority);
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(key, priority);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = CreateNode(key, priority);
            return root;
        }
    }
}

void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << "Key: " << temp->key << " Priority: " << temp->priority << endl;
    inorder(temp->right);
}

int main()
{
    Node *root = CreateNode(1, 4);
    root->left = CreateNode(2, 5);
    root->right = CreateNode(3, 2);
    root->left->left = CreateNode(4, 6);
    root->right->left = CreateNode(6, 3);
    root->right->right = CreateNode(9, 4);
    root->left->left->left = CreateNode(5, 5);
    root->left->left->right = CreateNode(8, 4);
    root->left->right = CreateNode(12, 2);
    root->right->right->left = CreateNode(11, 3);
    root->left->left->left->left = CreateNode(10, 4);

    cout << "Inorder traversal: ";
    inorder(root);

    return 0;
}
