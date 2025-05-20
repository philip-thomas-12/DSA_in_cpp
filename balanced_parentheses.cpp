#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& expr) {
    stack<char> st;
    for(char c : expr) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if(c == ')' || c == '}' || c == ']') {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expr;
    getline(cin, expr);
    if(isBalanced(expr)) cout << "Balanced" << endl;
    else cout << "Not balanced" << endl;
    return 0;
}
