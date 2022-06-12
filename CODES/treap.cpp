#include <iostream>
using namespace std;

struct TreapNode
{
    int key, priority;
    TreapNode *left, *right;
};

TreapNode *rightRotate(TreapNode *y)
{
    TreapNode *x = y->left, *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

TreapNode *leftRotate(TreapNode *x)
{
    TreapNode *y = x->right, *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

TreapNode *newNode(int key, int priority)
{
    TreapNode *temp = new TreapNode;
    temp->key = key;
    temp->priority = priority;
    temp->left = temp->right = NULL;
    return temp;
}

TreapNode *insert(TreapNode *root, int key, int priority)
{
    if (!root)
        return newNode(key, priority);

    if (key <= root->key)
    {
        root->left = insert(root->left, key, priority);
        if (root->left->priority < root->priority)
            root = rightRotate(root);
    }
    else
    {
        root->right = insert(root->right, key, priority);
        if (root->right->priority < root->priority)
            root = leftRotate(root);
    }
    return root;
}

void inorder(TreapNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << "key: " << root->key << " | priority: " << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
        inorder(root->right);
    }
}

int main()
{
    struct TreapNode *root = NULL;
    root = insert(root, 1, 4);
    root = insert(root, 2, 5);
    root = insert(root, 3, 2);
    root = insert(root, 4, 6);
    root = insert(root, 5, 5);
    root = insert(root, 6, 3);
    root = insert(root, 7, 4);
    root = insert(root, 8, 4);
    root = insert(root, 9, 4);
    root = insert(root, 10, 4);
    root = insert(root, 11, 3);
    root = insert(root, 12, 2);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    return 0;
}
