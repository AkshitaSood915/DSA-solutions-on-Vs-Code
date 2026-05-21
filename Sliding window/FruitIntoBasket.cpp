#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int l = 0, r = 0, maxLen = 0;
        map<int, int> mpp;

        while (r < arr.size()) {
            mpp[arr[r]]++;

            while (mpp.size() > 2) {
                mpp[arr[l]]--;

                if (mpp[arr[l]] == 0) {
                    mpp.erase(arr[l]);
                }

                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    int ans = obj.totalFruit(arr);

    cout << "Maximum fruits collected: " << ans << endl;

    return 0;
}