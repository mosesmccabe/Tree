#include "../Queues/_Queues.h"
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};
Node *root = nullptr;
// Create A Node
Node *NewNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->right = nullptr;
    temp->left = nullptr;
    return temp;
}
// Insert Function
Node *Insert(Node *temp, int userInput)
{
    if (temp == nullptr)
    {
        temp = NewNode(userInput);
        
    }
    else if(userInput <= temp->data) // go left
        temp->left = Insert(temp->left, userInput);
    else if(userInput >= temp->data)
        temp->right = Insert(temp->right, userInput);
    return temp;
}
// Search Function
bool Search(int userInput)
{
    Node *temp = root;
    
    while(temp != nullptr)
    {
        if (temp->data == userInput) return true;
        else if(userInput <= temp->data)
            temp = temp->left;
        else if(userInput >= temp->data)
            temp = temp->right;
    }
    return false;
}
// Find Min Value in Tree
int FindMin()
{
    Node *temp = root;
    if(temp == nullptr)
        return -1;
    while(temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}
// Find Max Value in Tree
int FindMax()
{
    Node *temp = root;
    if(temp == nullptr)
        return -1;
    while(temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Search Using Recurssion
bool recSearch(Node *temp, int value)
{
    if(temp == nullptr) return false;
    else if(temp->data == value) return true;
    else if(value <= temp->data)
        return recSearch(temp->left, value);
    else if(value >= temp->data)
        return recSearch(temp->right, value);
    return false;
}
// Find Hight of Tree
Node* max(Node *temp, Node *temp2)
{
    return (temp > temp2) ? temp : temp2;
}
int FindHeight(Node *temp)
{
    if(temp == nullptr) return -1;
    else return max(FindHeight(temp->left), FindHeight(temp->right)) + 1;
}
// Find Min Value in Tree using Recurssion
int recFindMin(Node*temp)
{
    if (temp == nullptr) return -1;   // Tree is Empty
    if(temp->left == nullptr) return temp->data;
    return  recFindMin(temp->left);
    return false;
}

// Find Max Value in Tree
int recFindMax(Node *temp)
{
    if (temp == nullptr) return -1;   // Tree is Empty
    if(temp->right == nullptr) return temp->data;
    return recFindMax(temp->right);
    return false;
}
//Level-Order Traversal
void LevelOrder()
{
    if(root == nullptr) return;
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node *curr = Q.front();
        cout << curr->data << " ";
        if(curr->left != nullptr) Q.push(curr->left);
        if(curr->right != nullptr) Q.push(curr->right);
        Q.pop();
    }
    cout << endl;
}

/* PreOrder (DLR)
    1. Data
    2. Visit left sub-tree
    3. Visit right sub-tree
 */
void PreOrder(Node *root)
{
    if (root == nullptr) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
/* InOrder (LDR)
   1. Visit left sub-tree
   2. Data
   3. Visit right sub-tree
*/
void InOrder(Node *root)
{
    if(root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
/* PostOrder (LRD)
   1. Visit left sub-tree
   2. Visit Right sub-tree
   3. Data
*/
void PostOrder(Node *root)
{
    if(root == nullptr) return;
    InOrder(root->left);
    InOrder(root->right);
    cout << root->data << " ";
}

// Check left side of tree
bool IsSubTreeLesser(Node *temp, int value);
// check the right side of the tree
bool IsSubTreeGreater(Node *temp, int value);
// Check if binary tree is
// a binary search tree.
bool IsBinarySearchTree(Node *root)
{
    if (root == nullptr) return true;
    return (leftSideLesser(root->left, root->data) &&
            rightSideGreater(root->right, root->data) &&
            IsBinarySearchTree(root->left) &&
            IsBinarySearchTree(root->right));
}



int main()
{
    root = Insert(root, 12);
    root = Insert(root, 20);
    root = Insert(root, 9);
    root = Insert(root, 17);
    root = Insert(root, 19);
    root = Insert(root, 18);
    root = Insert(root, 122);
    root = Insert(root, 8);
    root = Insert(root, 10);
    root = Insert(root, 11);
    root = Insert(root, 19);
    if(recSearch(root,2))
        cout << "Found\n";
    else
        cout << "Error: value not found\n";
    cout << "Find Min Value: " << FindMin() << endl;
    cout << "Find Min Value Using Recrussion: " << recFindMin(root) << endl;
    cout << "Find Min Value: " << FindMax() << endl;
    cout << "Find Min Value Using Recrussion: " << recFindMax(root) << endl;
    cout << "The Height of the tree is: " << FindHeight(root) << endl;
    LevelOrder();
    cout << "Preorder:\n";
    PreOrder(root);
    cout << endl;
    cout << "Inorder:\n";
    InOrder(root);
    cout << endl;
    cout << "Postorder\n";
    PostOrder(root);
    cout << endl;
    
    // Check if Binary Tree is a Binary Search Tree
    if(IsBinarySearchTree(root))
        cout << "Binary Tree is a Binary Search Tree\n";
    else
        cout << "Not a Binary Search Tree\n";
    
    return 0;
    
}





// Create A Node
Node *NewNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->right = nullptr;
    temp->left = nullptr;
    return temp;
}
// Insert Function
Node *Insert(Node *temp, int userInput)
{
    if (temp == nullptr)
    {
        temp = NewNode(userInput);
        
    }
    else if(userInput <= temp->data) // go left
        temp->left = Insert(temp->left, userInput);
    else if(userInput >= temp->data)
        temp->right = Insert(temp->right, userInput);
    return temp;
}
// Search Function
bool Search(int userInput)
{
    Node *temp = root;
    
    while(temp != nullptr)
    {
        if (temp->data == userInput) return true;
        else if(userInput <= temp->data)
            temp = temp->left;
        else if(userInput >= temp->data)
            temp = temp->right;
    }
    return false;
}
// Find Min Value in Tree
int FindMin()
{
    Node *temp = root;
    if(temp == nullptr)
        return -1;
    while(temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}
// Find Max Value in Tree
int FindMax()
{
    Node *temp = root;
    if(temp == nullptr)
        return -1;
    while(temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Search Using Recurssion
bool recSearch(Node *temp, int value)
{
    if(temp == nullptr) return false;
    else if(temp->data == value) return true;
    else if(value <= temp->data)
        return recSearch(temp->left, value);
    else if(value >= temp->data)
        return recSearch(temp->right, value);
    return false;
}
// Find Hight of Tree
Node* max(Node *temp, Node *temp2)
{
    return (temp > temp2) ? temp : temp2;
}
int FindHeight(Node *temp)
{
    if(temp == nullptr) return -1;
    else return max(FindHeight(temp->left), FindHeight(temp->right)) + 1;
}
// Find Min Value in Tree using Recurssion
int recFindMin(Node*temp)
{
    if (temp == nullptr) return -1;   // Tree is Empty
    if(temp->left == nullptr) return temp->data;
    return  recFindMin(temp->left);
    return false;
}

// Find Max Value in Tree
int recFindMax(Node *temp)
{
    if (temp == nullptr) return -1;   // Tree is Empty
    if(temp->right == nullptr) return temp->data;
    return recFindMax(temp->right);
    return false;
}
//Level-Order Traversal
void LevelOrder()
{
    if(root == nullptr) return;
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node *curr = Q.front();
        cout << curr->data << " ";
        if(curr->left != nullptr) Q.push(curr->left);
        if(curr->right != nullptr) Q.push(curr->right);
        Q.pop();
    }
    cout << endl;
}

/* PreOrder (DLR)
 1. Data
 2. Visit left sub-tree
 3. Visit right sub-tree
 */
void PreOrder(Node *root)
{
    if (root == nullptr) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
/* InOrder (LDR)
 1. Visit left sub-tree
 2. Data
 3. Visit right sub-tree
 */
void InOrder(Node *root)
{
    if(root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
/* PostOrder (LRD)
 1. Visit left sub-tree
 2. Visit Right sub-tree
 3. Data
 */
void PostOrder(Node *root)
{
    if(root == nullptr) return;
    InOrder(root->left);
    InOrder(root->right);
    cout << root->data << " ";
}



//Cheeck the left side of the tree
bool IsSubTreeLesser(Node *temp, int value)
{
    if(temp == nullptr) return true;
    return (temp->data <= value &&
            IsSubTreeLesser(temp->left, value) &&
            IsSubTreeLesser(temp->right, value));
}
// check the right side of the tree
bool IsSubTreeGreater(Node *temp, int value)
{
    if (temp == nullptr) return true;
    return (temp->data > value &&
            IsSubTreeGreater(temp->left, value) &&
            IsSubTreeGreater(temp->right, value));
}





