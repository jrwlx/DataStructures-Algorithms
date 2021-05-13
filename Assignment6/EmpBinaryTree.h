
#ifndef EMPBINARYTREE_H_
#define EMPBINARYTREE_H_

#include "Employee.h"
#include <string>

class EmpBinaryTree {
private:
    struct TreeNode {
        Employee e;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
    void insert(TreeNode *&, TreeNode *&); //done
    void destroySubTree(TreeNode *); //done
    void deleteNode(Employee, TreeNode *&); //done
    void makeDeletion(TreeNode *&); //done
    void displayInOrder(TreeNode *) const; //done
    void displayPreOrder(TreeNode *) const; //done
    void displayPostOrder(TreeNode *) const; //done
public:

    EmpBinaryTree() { root = nullptr; } //done
    ~EmpBinaryTree() { destroySubTree(root); } //done
    void insertEmployee(Employee); //done
    bool searchEmployee(Employee); //done
    Employee getEmployee(string); //done
    void remove(Employee); //done
    void displayInOrder() const { displayInOrder(root); } //done
    void displayPreOrder() const { displayPreOrder(root); } //done
    void displayPostOrder() const { displayPostOrder(root); } //done
};

#endif /* EMPBINARYTREE_H_ */
