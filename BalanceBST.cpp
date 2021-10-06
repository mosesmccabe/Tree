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

/**************************
      Create A Node
***************************/
Node *NewNode(int);



/*****************************
    Insert value to Tree
******************************/
Node *Insert(Node *, int );



/*****************************
    Search for Value in Tree
******************************/
bool Search(int );
/******************************
   Search Using Recurssion
*******************************/
bool recSearch(Node *, int);



/********************************************
 Find Min Value in Tree
 ********************************************/
int FindMin();
/**********************************************
 Find Min Value in Tree using Recurssion
************************************************/
int recFindMin(Node*);



/********************************************
 Find Max Value in Tree
 ********************************************/
int FindMax();
/**********************************************
 Find Min Value in Tree using Recurssion
***********************************************/
int recFindMax(Node *);




/*******************************************
 Find Hight of Tree
 ********************************************/
Node* max(Node *, Node *);
int FindHeight(Node *);



/**********************************************
     Traversal List
***********************************************/
//Level-Order Traversal
void LevelOrder();
/* PreOrder (DLR)
    1. Data
    2. Visit left sub-tree
    3. Visit right sub-tree
 */
void PreOrder(Node *);
/* InOrder (LDR)
   1. Visit left sub-tree
   2. Data
   3. Visit right sub-tree
*/
void InOrder(Node *);
/* PostOrder (LRD)
   1. Visit left sub-tree
   2. Visit Right sub-tree
   3. Data
*/
void PostOrder(Node *);



/*********************************************
  Check if Binary Tree is Binary Search Tree
**********************************************/
// Check left side of tree
bool IsSubTreeLesser(Node *temp, int value);
// check the right side of the tree
bool IsSubTreeGreater(Node *temp, int value);
// Check if binary tree is
// a binary search tree.
bool IsBinarySearchTree(Node *);



/*************************
   Delete a Node from BST
 *************************/
Node *Delete(Node*, int);
Node *FindRightMin(Node*);


/*****************************************
     Inorder Successor in a BST
******************************************/
int GetSuccessor(int value);
/**********************************************
 Search for Value in Tree but return the address
 ***********************************************/
Node *find(int );


int main()
{
    int userInput;
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
        cout << "Binary Tree is a Binary Search Tree\n\n";
    else
        cout << "Not a Binary Search Tree\n\n";
    cout << "Enter Node to Delete: ";
    cin >> userInput;
    root = Delete(root, userInput);
    InOrder(root);
    cout << endl;
    cout << root->data << endl;
    cout << "Inorder Successor\n";
    InOrder(root);
    cout << "\nEnter Value to find Successor: ";
    cin >> userInput;
    if(GetSuccessor(userInput) == -1)
        cout << "Invalid value\n";
    else
        cout << GetSuccessor(userInput) << endl;

    
    return 0;
    
}





/********************************************
           Create A Node
 ********************************************/
Node *NewNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->right = nullptr;
    temp->left = nullptr;
    return temp;
}

/********************************************
          Insert value to Tree
 ********************************************/
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


/********************************************
         Search for Value in Tree
 ********************************************/
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
/********************************************
    Search Using Recurssion
 *********************************************/
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


/********************************************
        Find Min Value in Tree
********************************************/
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
/**********************************************
 Find Min Value in Tree using Recurssion
 ************************************************/
int recFindMin(Node*temp)
{
    if (temp == nullptr) return -1;   // Tree is Empty
    if(temp->left == nullptr) return temp->data;
    return  recFindMin(temp->left);
    return false;
}

/********************************************
         Find Max Value in Tree
*********************************************/
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
/**********************************************
 Find Max Value in Tree using Recursion
 ***********************************************/
int recFindMax(Node *temp)
{
    if (temp == nullptr) return -1;   // Tree is Empty
    if(temp->right == nullptr) return temp->data;
    return recFindMax(temp->right);
    return false;
}



/*******************************************
       Find Hight of Tree
********************************************/
Node* max(Node *temp, Node *temp2)
{
    return (temp > temp2) ? temp : temp2;
}

int FindHeight(Node *temp)
{
    if(temp == nullptr) return -1;
    else return max(FindHeight(temp->left), FindHeight(temp->right)) + 1;
}



/******************************************************
                Traversal List
 ******************************************************/
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



/*********************************************
 Check if Binary Tree is Binary Search Tree
 **********************************************/
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
// Check if Tree is a Binary Search Tree
bool IsBinarySearchTree(Node *root)
{
    if (root == nullptr) return true;
    return (IsSubTreeLesser(root->left, root->data) &&
            IsSubTreeGreater(root->right, root->data) &&
            IsBinarySearchTree(root->left) &&
            IsBinarySearchTree(root->right));
}



/************************************************
           Delete Value in Tree
      [Case I] No Child
        1. cut link
        2. delete node from Memory
 
      [Case II] One Child
        1. cut link
        2. set link to next link
        3. delete node
 
      [Case III] Two Childern
        1. find min in right subtree
        2. copy the value in tagetted node
        3. delete duplicate from right-subtree
 
*************************************************/
Node *FindRightMin(Node *temp)
{
    while(temp->left != nullptr)
        temp = temp->left;
    return temp;
    
}
//Delete Node for BST
Node *Delete(Node *root, int userInput)
{
    if(root == nullptr) return root;
    else if(userInput < root->data)
        root->left = Delete(root->left, userInput);
    else if(userInput > root->data)
        root->right = Delete(root->right, userInput);
    else
    {
        /* [Case 1] No Child
             - cut link
             - delete node from memory
        */
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        /* [Case 2] One Child
             - cut link
             - set link to next link
             - delete node
        */
        else if(root->left == nullptr)
        {
            Node *temp =  root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        /* [Case 3] Two Children
             - find min in right-subtree
             - copy the value in targetted
               node
             - delete duplicate from
               right-subtree
        */
        else
        {
            Node *temp = FindRightMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,userInput);
        }
    }
    return root;
}


/**************************************************
    Inorder Successor in a BST
     [Case I] Node has right of subtree
       - Find min in the right subtree
 
     [Case II] No Right Subtree
       - Go the the nearest ancestor for 
         which giiven node would be in the
         left subtree.
 **************************************************/
int GetSuccessor(int value)
{
    
    Node *curr = find(value);
    if(curr->right != nullptr)
    {
        return recFindMin(curr->right);
    }
    //[Case II] No Right Subtree
    else
    {
        Node *ancestor = root, *successor = nullptr; 
        while(curr != ancestor)
        {
            successor = ancestor;
            if(curr->data < ancestor->data)
                ancestor = ancestor->left;
            else
                ancestor = ancestor->right;
        }
        return successor->data;
    }
}
/**************************************************
  Search for Value in Tree but return the address
 **************************************************/
Node *find(int value)
{
    Node *temp = root;
    while (root != nullptr)
    {
        if(value == temp->data) return temp;
        else if(value < temp->data)
            temp = temp->left;
        else if(value > temp->data)
            temp = temp->right;
    }
    return nullptr;
}

