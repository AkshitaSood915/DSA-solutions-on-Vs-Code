#include <bits/stdc++.h>
using namespace std;

// Structure to store job details
struct Job {
    int id;      // Job ID
    int dead;    // Deadline
    int profit;  // Profit
};

class Solution {
public:

    // Sort jobs in decreasing order of profit
    static bool comparison(Job a, Job b) {
        return a.profit > b.profit;
    }

    pair<int, int> JobScheduling(Job arr[], int n) {

        // Sort all jobs by profit
        sort(arr, arr + n, comparison);

        // Find the maximum deadline
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Hash array to mark occupied time slots
        vector<int> hash(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        // Try to schedule each job
        for (int i = 0; i < n; i++) {

            // Find the latest free slot before deadline
            for (int j = arr[i].dead; j >= 1; j--) {

                // If slot is free
                if (hash[j] == -1) {

                    // Assign current job to this slot
                    hash[j] = arr[i].id;

                    countJobs++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};

int main() {

    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job arr[n];

    cout << "Enter Job ID, Deadline and Profit:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    Solution ob;

    pair<int, int> ans = ob.JobScheduling(arr, n);

    cout << "\nJobs Done = " << ans.first << endl;
    cout << "Total Profit = " << ans.second << endl;

    return 0;
}