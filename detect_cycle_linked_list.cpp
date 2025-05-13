#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    if(n <= 0) {
        cout << "No cycle" << endl;
        return 0;
    }
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
    // Read position to create cycle (-1 for no cycle)
    int pos;
    cin >> pos;
    if(pos >= 0) {
        Node* cycleNode = head;
        for(int i = 0; i < pos; i++) {
            if(cycleNode->next != nullptr) cycleNode = cycleNode->next;
        }
        tail->next = cycleNode;
    }
    bool cycleExists = hasCycle(head);
    if(cycleExists) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;
    return 0;
}
