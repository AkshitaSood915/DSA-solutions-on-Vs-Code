#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count nice subarrays
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    // Helper function to count subarrays with at most k odd numbers
    int atMost(vector<int>& nums, int k) {

        if (k < 0)
            return 0;

        int left = 0;
        int oddCount = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Count odd numbers
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            // Shrink window if odd count exceeds k
            while (oddCount > k) {

                if (nums[left] % 2 != 0) {
                    oddCount--;
                }

                left++;
            }

            // Add valid subarrays
            count += (right - left + 1);
        }

        return count;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int ans = obj.numberOfSubarrays(nums, k);

    cout << "Number of nice subarrays: " << ans << endl;

    return 0;
}