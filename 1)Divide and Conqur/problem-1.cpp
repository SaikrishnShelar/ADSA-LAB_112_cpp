//find the max sum subarray
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int crossSum(vector<int>& arr, int l, int m, int r) {
    int sum = 0, left = INT_MIN, right = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        left = max(left, sum);
    }
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        right = max(right, sum);
    }
    return left + right;
}

int maxSubarray(vector<int>& arr, int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    return max({ maxSubarray(arr, l, m), maxSubarray(arr, m + 1, r), crossSum(arr, l, m, r) });
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cout << maxSubarray(arr, 0, n - 1);
}
