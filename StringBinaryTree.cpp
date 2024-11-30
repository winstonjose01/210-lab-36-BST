// Implementation file for the IntBinaryTree class
#include <iostream>
#include "StringBinaryTree.h"
using namespace std;

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.
void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

// insertNode creates a new node to hold val as its value,
// and passes it to the insert function.                  
void StringBinaryTree::insertNode(string val) {
   TreeNode *newNode;      // Pointer to a new node.

   // Create a new node and store val in it.
   newNode = new TreeNode;
   newNode->value = val;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   

// searchNode determines if a value is present in  
// the tree. If so, the function returns true.     
// Otherwise, it returns false.                    
bool StringBinaryTree::searchNode(string val) {
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == val)
         return true;
      else if (val < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

bool StringBinaryTree::modifyNode(string val, string newval) {
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (nodePtr->value == val){
         remove(val);
         insertNode(newval);
         cout << val << " has been modified to " << newval;
         return true;
      }
      else if (val < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

// remove calls deleteNode to delete the      
// node whose value member is the same as val.
void StringBinaryTree::remove(string val) {
   deleteNode(val, root);
}

// deleteNode deletes the node whose value 
// member is the same as val.              
void StringBinaryTree::deleteNode(string val, TreeNode *&nodePtr) {
   if (val < nodePtr->value)
      deleteNode(val, nodePtr->left);
   else if (val > nodePtr->value)
      deleteNode(val, nodePtr->right);
   else
      if (!nodePtr){
         cout << "Value not found in the tree. \n";
         return;
      }
      makeDeletion(nodePtr);
}


// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

// The displayPreOrder member function displays the values      
// in the subtree pointed to by nodePtr, via preorder traversal.
void StringBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

// The displayPostOrder member function displays the values     
// in the subtree pointed to by nodePtr, via postorder traversal.
void StringBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}