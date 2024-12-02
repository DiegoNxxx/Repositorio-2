#include "AVLTree.h"

// Implementación de AVLNode
AVLNode::AVLNode(User* user) : user(user), left(nullptr), right(nullptr), height(1) {}

// Implementación de AVLTree
AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(AVLNode* node) {
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Realizar la rotación
    x->right = y;
    y->left = T2;

    // Actualizar las alturas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Realizar la rotación
    y->left = x;
    x->right = T2;

    // Actualizar las alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, User* user) {
    // Insertar de manera normal en un BST
    if (!node)
        return new AVLNode(user);

    if (user->id < node->user->id)
        node->left = insert(node->left, user);
    else if (user->id > node->user->id)
        node->right = insert(node->right, user);
    else
        return node; // No se permiten claves duplicadas

    // Actualizar la altura del nodo
    node->height = 1 + max(height(node->left), height(node->right));

    // Calcular el factor de balance
    int balance = balanceFactor(node);

    // Si el nodo se desbalancea, realizar las rotaciones correspondientes

    // Caso de desbalanceo: izquierda-izquierda
    if (balance > 1 && user->id < node->left->user->id)
        return rightRotate(node);

    // Caso de desbalanceo: derecha-derecha
    if (balance < -1 && user->id > node->right->user->id)
        return leftRotate(node);

    // Caso de desbalanceo: izquierda-derecha
    if (balance > 1 && user->id > node->left->user->id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso de desbalanceo: derecha-izquierda
    if (balance < -1 && user->id < node->right->user->id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::inorder(AVLNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << "ID: " << node->user->id << ", Name: " << node->user->name << ", Email: " << node->user->email << endl;
        inorder(node->right);
    }
}

void AVLTree::deleteUser(AVLNode*& node, int id) {
    if (node == nullptr) return;

    if (id < node->user->id)
        deleteUser(node->left, id);
    else if (id > node->user->id)
        deleteUser(node->right, id);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(node->right);
            node->user = temp->user;
            deleteUser(node->right, temp->user->id);
        }
    }

    if (node == nullptr) return;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = balanceFactor(node);

    if (balance > 1 && balanceFactor(node->left) >= 0)
        node = rightRotate(node);

    if (balance < -1 && balanceFactor(node->right) <= 0)
        node = leftRotate(node);

    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }

    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}
