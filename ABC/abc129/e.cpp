#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}

int dp[100005][2];
const long long MOD = 1000000007;
int main() {
    string S;
    cin >> S;
    dp[0][0] = 1;
    int n = S.size();
    rep(i, 0, n) {
        if(S[i] == '0') {

            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1];

            dp[i + 1][1] += dp[i][1] * 2 % MOD;
            dp[i + 1][1] %= MOD;
        } else {
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;

            dp[i + 1][0] = dp[i][0] * 2 % MOD;
            dp[i + 1][1] += dp[i][1] * 2 % MOD;
            dp[i + 1][1] %= MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}