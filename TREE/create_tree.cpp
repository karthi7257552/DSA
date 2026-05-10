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

int main()
{
    // Creating a simple binary tree

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Tree created successfully";

    return 0;
}