#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(k > n) {
        cout << 0 << endl;
        return 0;
    }
    int window_sum = 0;
    for(int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    int max_sum = window_sum;
    for(int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    cout << max_sum << endl;
    return 0;
}
