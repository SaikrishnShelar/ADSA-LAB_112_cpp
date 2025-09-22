#include <iostream>
using namespace std;

// Function to count the number of ways to make the given sum
int coinChangeWays(int coins[], int N, int sum) {
    // Create DP array
    int dp[sum + 1];

    // Initialize all dp values as 0
    for (int i = 0; i <= sum; i++) {
        dp[i] = 0;
    }

    // Base case: 1 way to make sum 0 (choose no coins)
    dp[0] = 1;

    // Process each coin
    for (int i = 0; i < N; i++) {
        int coin = coins[i];
        for (int j = coin; j <= sum; j++) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[sum];
}

int main() {
    int N, sum;

    // Taking input
    cout << "Enter number of coin types: ";
    cin >> N;

    int coins[N];
    cout << "Enter coin values: ";
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    cout << "Enter total sum: ";
    cin >> sum;

    // Calculate and print result
    cout << "Number of ways to make sum " << sum << " = "
         << coinChangeWays(coins, N, sum) << endl;
}
