#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l = 0, r = 0, zeroes = 0, maxLen = 0;

        while (r < nums.size()) {

            if (nums[r] == 0)
                zeroes++;

            if (zeroes > k) {

                if (nums[l] == 0)
                    zeroes--;

                l++;
            }

            if (zeroes <= k) {
                maxLen = max(maxLen, r - l + 1);
            }

            r++;
        }

        return maxLen;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements (0 or 1): ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    Solution s;

    cout << "Maximum consecutive ones = "
         << s.longestOnes(nums, k);

    return 0;
}
 
