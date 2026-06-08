#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& arr) {
    int n = arr.size();
    int jumps = 0, l = 0, r = 0;

    while (r < n - 1) {
        long long farthest = 0;

        for (int i = l; i <= r; i++) {
            farthest = max(farthest, 1LL * i + arr[i]);
        }

        l = r + 1;
        r = (int)farthest;
        jumps++;
    }

    return jumps;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum jumps = " << jump(arr) << endl;

    return 0;
}