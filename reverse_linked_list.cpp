#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while(curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    if(n <= 0) return 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if(head == nullptr) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
    head = reverseList(head);
    Node* curr = head;
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
