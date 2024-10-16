#include "BinaryTree.h"
#include <iostream>

using namespace std;

Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

Node* BinaryTree::search(Node* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    }

    return search(node->right, value);
}

void BinaryTree::preOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BinaryTree::inOrder(Node* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void BinaryTree::postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}
