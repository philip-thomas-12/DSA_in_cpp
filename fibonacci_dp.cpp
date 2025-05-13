#include <iostream>
#include <vector>
using namespace std;

// Filename: fibonacci_dp.cpp
// Description: Compute the nth Fibonacci number using dynamic programming.

int main() {
    int n;
    cin >> n;
    if(n <= 1) {
        cout << n << endl;
        return 0;
    }
    vector<int> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << fib[n] << endl;
    return 0;
}
