#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int key) {
    if(root == nullptr) return new Node(key);
    if(key < root->data) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

bool searchBST(Node* root, int key) {
    if(root == nullptr) return false;
    if(root->data == key) return true;
    if(key < root->data) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertNode(root, val);
    }
    int key;
    cin >> key;
    cout << (searchBST(root, key) ? "Found" : "Not found") << endl;
    return 0;
}
