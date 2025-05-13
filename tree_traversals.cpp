#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(const vector<int>& arr, int i) {
    if(i >= arr.size() || arr[i] == -1) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, 2*i + 1);
    root->right = buildTree(arr, 2*i + 2);
    return root;
}

void preorder(Node* root) {
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* root = buildTree(arr, 0);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
