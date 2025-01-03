#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) 
    {
        data = value;
        left = nullptr;
        right = nullptr;
          }
};
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
svoid inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;

    cout << "Enter" <<n<< "values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order Traversal : ";
    inorder(root);
    cout << endl;

    cout << "Pre-order Traversal : ";
    preorder(root);
    cout << endl;

    cout << "Post-order Traversal  : ";
    postorder(root);
    cout << endl;

    return 0;

}
