#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0; // cookie pointer
        int r = 0; // student pointer

        while (l < s.size() && r < g.size()) {

            // If current cookie can satisfy current student
            if (s[l] >= g[r]) {
                r++;
            }

            // Move to next cookie
            l++;
        }

        return r;
    }
};

int main() {

    int n, m;

    cout << "Enter number of students: ";
    cin >> n;

    vector<int> g(n);

    cout << "Enter greed factors: ";
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    cout << "Enter number of cookies: ";
    cin >> m;

    vector<int> s(m);

    cout << "Enter cookie sizes: ";
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    Solution obj;

    int ans = obj.findContentChildren(g, s);

    cout << "Maximum content children: " << ans << endl;

    return 0;
}