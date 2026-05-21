#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, r = 0, l = 0;
        map<char, int> mpp;
        int maxFreq = 0;

        while (r < s.length()) {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                mpp[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    int ans = obj.characterReplacement(s, k);

    cout << "Maximum length of substring = " << ans << endl;

    return 0;
} 
