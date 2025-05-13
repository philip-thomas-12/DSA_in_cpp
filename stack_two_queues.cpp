#include <iostream>
#include <queue>
using namespace std;


class MyStack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if(!q1.empty()) q1.pop();
    }
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    int n;
    cin >> n;  // number of elements to push
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    int m;
    cin >> m;  // number of pops
    for(int i = 0; i < m; i++) {
        st.pop();
    }
    if(!st.empty())
        cout << st.top() << endl;
    else
        cout << -1 << endl;
    return 0;
}
