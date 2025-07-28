
//to find the smallest number whose factorial contain n trailing 0
#include <iostream>
using namespace std;

int countTrailingZeros(int num) {
    int count = 0;
    int power = 5;
    while (num / power > 0) {
        count += num / power;
        power *= 5;
    }
    return count;
}

int findSmallestNumber(int n) {
    int low = n;
    int high = n * 5;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int zeros = countTrailingZeros(mid);

        if (zeros < n) {
            low = mid + 1;
        } else {
            if (zeros == n) {
                ans = mid;
            }
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of trailing zeros: ";
    cin >> n;

    int result = findSmallestNumber(n);

    if (result == -1) {
        cout << "Invalid input. No number found whose factorial has exactly " << n << " trailing zeros.\n";
    } else {
        cout << "Smallest number whose factorial has exactly " << n << " trailing zeros is: " << result << endl;
    }

    return 0;
}
