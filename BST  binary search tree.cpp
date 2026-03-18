#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// BST class
class BST {
    Node* root;  // Root node

public:
    BST() { root = NULL; }

    // Insert a value into the BST
    void insert(int val) {
        Node* ptr = new Node;
        ptr->data = val;
        ptr->left = ptr->right = NULL;

        if (root == NULL) { // Empty tree
            root = ptr;
            return;
        }

        Node* curr = root;
        Node* parent = NULL;

        while (curr != NULL) {
            parent = curr;
            if (val >= curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if (val >= parent->data)
            parent->right = ptr;
        else
            parent->left = ptr;
    }

    // Preorder traversal: Root -> Left -> Right
    void displayPreorder(Node* temp) {
        if (temp == NULL) return;
        cout << temp->data << " ";
        displayPreorder(temp->left);
        displayPreorder(temp->right);
    }

    // Inorder traversal: Left -> Root -> Right
    void displayInorder(Node* temp) {
        if (temp == NULL) return;
        displayInorder(temp->left);
        cout << temp->data << " ";
        displayInorder(temp->right);
    }

    // Postorder traversal: Left -> Right -> Root
    void displayPostorder(Node* temp) {
        if (temp == NULL) return;
        displayPostorder(temp->left);
        displayPostorder(temp->right);
        cout << temp->data << " ";
    }

    // Getter for root
    Node* getRoot() { return root; }
};

// Main function
int main() {
    BST tree;

    // Insert nodes
    tree.insert(45);
    tree.insert(88);
    tree.insert(15);
    tree.insert(60);
    tree.insert(11);
    tree.insert(25);
    tree.insert(6);
    tree.insert(21);
    tree.insert(30);
    tree.insert(9);

    // Display BST
    cout << "BST Preorder Traversal: ";
    tree.displayPreorder(tree.getRoot());
    cout << "\n";

    cout << "BST Inorder Traversal: ";
    tree.displayInorder(tree.getRoot());
    cout << "\n";

    cout << "BST Postorder Traversal: ";
    tree.displayPostorder(tree.getRoot());
    cout << "\n";

    return 0;
}

