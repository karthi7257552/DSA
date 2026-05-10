#include <iostream>
using namespace std;

// Structure of node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Function to create node
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert node in BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Input values
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    // Display inorder traversal
    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}