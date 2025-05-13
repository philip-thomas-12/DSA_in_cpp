#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }
    void dequeue() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()) s2.pop();
    }
    int front() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()) return s2.top();
        return -1; // queue is empty
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    int n;
    cin >> n;  // number of elements to enqueue
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }
    int m;
    cin >> m; // number of dequeues
    for(int i = 0; i < m; i++) {
        q.dequeue();
    }
    if(!q.empty())
        cout << q.front() << endl;
    else
        cout << -1 << endl;
    return 0;
}
