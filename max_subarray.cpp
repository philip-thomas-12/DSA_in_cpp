#include <iostream>
#include <vector>
using namespace std;

// Filename: max_subarray.cpp
// Description: Find maximum subarray sum using Kadane's Algorithm.

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_so_far = arr[0];
    int current_max = arr[0];
    for(int i = 1; i < n; i++) {
        current_max = max(arr[i], current_max + arr[i]);
        max_so_far = max(max_so_far, current_max);
    }
    cout << max_so_far << endl;
    return 0;
}
