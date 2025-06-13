
#include <iostream>
#include <vector>
using namespace std;

// Filename: binary_search.cpp
// Description: Perform binary search on a sorted array and return index of target (or -1 if not found).

int binarySearch(const vector<int>& arr, int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;
    int index = binarySearch(arr, 0, n - 1, target);
    cout << index << endl;
    return 0;
}
