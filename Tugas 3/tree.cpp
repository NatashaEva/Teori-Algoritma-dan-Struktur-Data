#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}
    void inorderTraversal(Node* node);
    void insert(int val);
    Node* insertRec(Node* node, int val);
};

void BinaryTree::inorderTraversal(Node* node) {
    if (node == nullptr)
        return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

Node* BinaryTree::insertRec(Node* node, int val) {
    if (node == nullptr) {
        node = new Node(val);
        return node;
    }

    if (val < node->data)
        node->left = insertRec(node->left, val);
    else if (val > node->data)
        node->right = insertRec(node->right, val);

    return node;
}

void BinaryTree::insert(int val) {
    root = insertRec(root, val);
}

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(1);
    tree.insert(27);
    tree.insert(12);
    tree.insert(54);
    tree.insert(2);

    cout << "Inorder dari binary tree: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
