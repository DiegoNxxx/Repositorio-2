#ifndef AVLTREE_H
#define AVLTREE_H

#include "User.h"
#include <algorithm>
#include <iostream>
using namespace std;

class AVLNode {
public:
    User* user;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(User* user);
};

class AVLTree {
public:
    AVLNode* root;

    AVLTree();

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert(AVLNode* node, User* user);
    void inorder(AVLNode* node);
    void deleteUser(AVLNode*& node, int id);
    AVLNode* minValueNode(AVLNode* node);
};

#endif // AVLTREE_H
