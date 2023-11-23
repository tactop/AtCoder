#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

string s;
long long dp[100010][13];
const long long MOD = 1000000007;
int main() {
    cin >> s;
    int n = s.length();
    dp[0][0] = 1;

    rep(i, 0, n) {
        int t;
        if(s[i] == '?') {
            t = -1;
        } else {
            t = s[i] - '0';
        }

        rep(j, 0, 13) {
            if(t != -1) {
                int nx = (j * 10 + t) % 13;
                dp[i + 1][nx] += dp[i][j];

            } else {
                rep(k, 0, 10) {
                    int nx = (j * 10 + k) % 13;
                    dp[i + 1][nx] += dp[i][j];
                }
            }
        }
        rep(j, 0, 13) { dp[i + 1][j] %= MOD; }
    }
    cout << dp[n][5] << endl;
}