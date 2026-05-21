#include <bits/stdc++.h>
using namespace std;

int longestSubstringKDistinct(string s, int k) {
    int maxLen = 0, l = 0, r = 0;
    map<char, int> mpp;

    while (r < s.length()) {
        mpp[s[r]]++;

        while (mpp.size() > k) {
            mpp[s[l]]--;

            if (mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }

            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Length = " << longestSubstringKDistinct(s, k);

    return 0;
}