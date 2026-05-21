#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum > k) {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};

int main() {

    int n;

    cout << "\nEnter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "\nEnter binary array elements (0 or 1): ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int goal;

    cout << "\nEnter goal sum: ";
    cin >> goal;

    Solution obj;

    int ans = obj.numSubarraysWithSum(nums, goal);

    cout << "\nNumber of subarrays with sum "
         << goal << " is: " << ans << endl;

    return 0;
}