#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    int count = 0;
    int n = s.size();
    vector<long long> dp1(n);
    vector<long long> dp2(n);
    dp1[0] = s[0] - '0';
    dp2[0] = 11 - (s[0] - '0');
    rep(i, 1, n) {
        int t = s[i] - '0';
        dp1[i] = min(dp1[i - 1] + t, dp2[i - 1] + t);
        dp2[i] = min(dp1[i - 1] + 11 - t, dp2[i - 1] + 9 - t);
    }
    // rep(i, 0, n) {
    //     int t = s[0] - '0';
    //     cout << dp1[i] << "," << dp2[i] << endl;
    // }
    cout << min(dp1[n - 1], dp2[n - 1]) << endl;
}
