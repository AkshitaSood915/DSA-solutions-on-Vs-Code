#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);

        int left = 0;
        int right = 0;
        int maxLen = 0;

        while (right < s.size()) {

            // If character already exists
            if (hash[s[right]] != -1) {

                // Check if inside current window
                if (hash[s[right]] >= left) {
                    left = hash[s[right]] + 1;
                }
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);

            // Store latest index
            hash[s[right]] = right;

            right++;
        }

        return maxLen;
    }
};

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    int ans = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: ";
    cout << ans << endl;

    return 0;
}