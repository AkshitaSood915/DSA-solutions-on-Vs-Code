#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int lsum = 0, rsum = 0, maxSum = 0;

        int n = cardPoints.size();

        // Take first k elements from left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxSum = lsum;

        int rindex = n - 1;

        // Remove from left and add from right
        for (int i = k - 1; i >= 0; i--) {

            lsum -= cardPoints[i];

            rsum += cardPoints[rindex];

            rindex--;

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> cardPoints(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> cardPoints[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int ans = obj.maxScore(cardPoints, k);

    cout << "Maximum score is: " << ans << endl;

    return 0;
} 
