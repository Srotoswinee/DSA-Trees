#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool identicalTrees(Node* a, Node* b) {
    if (a == nullptr && b == nullptr)
        return true;
    if (a != nullptr && b != nullptr) {
        return (a->data == b->data
                && identicalTrees(a->left, b->left)
                && identicalTrees(a->right, b->right));
    }
    return false;
}

int main() {
    Node* root1 = newNode(1);
    Node* root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if (identicalTrees(root1, root2))
        cout << "Both trees are identical.";
    else
        cout << "Trees are not identical.";

    // Clean up memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
