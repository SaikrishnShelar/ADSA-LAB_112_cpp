/* Implement a problem of minimum work to be done per day to finish given tasks within D days problem.  
Statement: Given an array task [] of size N denoting amount of work to be done for each task, the problem is to find the minimum amount of work to be done on each day so that all the tasks can be completed in at most D days. 
Note: On one day work can be done for only one task. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int minHours(vector<int>& tasks, int h) {
        long long low = 1;
        long long high = *max_element(tasks.begin(), tasks.end());

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long total_hours = 0;

            for (int task : tasks) {
                total_hours += (task + mid - 1) / mid;  // ceiling division
                if (total_hours > h) {
                    break;
                }
            }

            if (total_hours <= h) {
                high = mid - 1;  // try smaller
            } else {
                low = mid + 1;   // need more hours
            }
        }

        return (int)low;
    }
};

int main() {
    vector<int> tasks = {30, 11, 23, 4, 20};
    int h = 6;
    int ans = Solution::minHours(tasks, h);
    cout << "Minimum hours required: " << ans << endl;
    return 0;
}
