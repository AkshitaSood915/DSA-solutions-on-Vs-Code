#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& arr) {
    int n = arr.size();
    int maxInd = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxInd)
            return false;

        maxInd = max(maxInd, i + arr[i]);
    }

    return true;
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

    if (canJump(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}
