
#include "EmpBinaryTree.h"
#include "Employee.h"
#include <iostream>

using namespace std;

void EmpBinaryTree::destroySubTree(TreeNode *nodePtr) {
    if (nodePtr != nullptr) {
        if (nodePtr->left != nullptr)
            destroySubTree(nodePtr->left);
        if (nodePtr->right != nullptr)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//insert functions
void EmpBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->e.getName() <= nodePtr->e.getName()) //"A" is less than "M"
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void EmpBinaryTree::insertEmployee(Employee a) {
    TreeNode *newNode = new TreeNode;
    newNode->e = a;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}
//end of insert functions

//remove functions
void EmpBinaryTree::remove(Employee a) {
    deleteNode(a, root);
}

void EmpBinaryTree::deleteNode(Employee a, TreeNode *&nodePtr) {
    if (a.getName() < nodePtr->e.getName())
        deleteNode(a, nodePtr->left);
    else if (a.getName() > nodePtr->e.getName())
        deleteNode(a, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

void EmpBinaryTree::makeDeletion(TreeNode *&nodePtr) {
    TreeNode *tempNodePtr = nullptr;
    if (nodePtr == nullptr)
        return;
    else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left != nullptr)
            tempNodePtr = tempNodePtr->left;

        tempNodePtr->left = tempNodePtr->left;
        tempNodePtr = nodePtr;

        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}
//end of remove functions

bool EmpBinaryTree::searchEmployee(Employee a) {
    TreeNode *nodePtr = root;
    while (nodePtr != nullptr) {
        if (nodePtr->e.getName() == a.getName())
            return true;
        else if (a.getName() < nodePtr->e.getName())
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

Employee EmpBinaryTree::getEmployee(string a) {
    Employee tempEmployee;
    tempEmployee.setName(a);
    TreeNode *nodePtr = root;
    while (nodePtr != nullptr) {
        if (nodePtr->e.getName() == tempEmployee.getName())
            return nodePtr->e;
        else if (tempEmployee.getName() < nodePtr->e.getName())
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return root->e;
}

void EmpBinaryTree::displayInOrder(TreeNode *nodePtr) const {
    if (nodePtr != nullptr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->e.getName() << endl;
        cout << nodePtr->e.getNumber() << endl;
        cout << nodePtr->e.getHireDate() << endl;
        displayInOrder(nodePtr->right);
    }
}

void EmpBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
    if (nodePtr != nullptr) {
        cout << nodePtr->e.getName() << endl;
        cout << nodePtr->e.getNumber() << endl;
        cout << nodePtr->e.getHireDate() << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void EmpBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
    if (nodePtr != nullptr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->e.getName() << endl;
        cout << nodePtr->e.getNumber() << endl;
        cout << nodePtr->e.getHireDate() << endl;
    }
}




