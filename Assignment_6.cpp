
/*
Implement a problem of maximizing Profit by trading stocks based on given rate per day.  
Statement: Given an array arr[] of N positive integers which denotes the cost of selling and buying stock on each of the N days. The task is to find the maximum profit that can be earned by buying a stock on or selling all previously bought stocks on a particular day.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int profit = 0;
        int buy = prices[0];
        bool holding = false;

        for (int i = 1; i < n; i++) {
            if (!holding && prices[i] > prices[i - 1]) {
                buy = prices[i - 1];
                holding = true;
            }

            if (holding && prices[i] < prices[i - 1]) {
                profit += prices[i - 1] - buy;
                holding = false;
            }
        }

        if (holding) {
            profit += prices[n - 1] - buy;
        }

        return profit;
    }
};

int main() {
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};
    cout << "Maximum Profit: " << Solution::maxProfit(arr) << endl;
    return 0;
}
