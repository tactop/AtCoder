#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[100][9];
const int MOD = 1000000007;
long long ruijo(int x, int n) {
    long long res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    //初期値(H=0)
    if(W == 1) {
        cout << 1 << endl;
        return 0;
    }
    rep(k, 0, W) {
        if(k == 0) {
            dp[0][0] = 1;
        } else {
            dp[0][k] = 0;
        }
    }
    // H=1の全パターン数
    int pat[9];
    pat[0] = 1;
    pat[1] = 1;
    rep(w, 2, 9) { pat[w] = pat[w - 1] + pat[w - 2]; }
    rep(h, 1, H + 1) {
        rep(k, 0, W) {
            if(k == 0) {
                dp[h][k] = (dp[h - 1][k] * pat[W - 1]) +
                           (dp[h - 1][k + 1] * pat[W - 2]);

                dp[h][k] = dp[h][k] % MOD;
            } else if(k == W - 1) {
                dp[h][k] = (dp[h - 1][k] * pat[W - 1]) +
                           (dp[h - 1][k - 1] * pat[W - 2]);

                dp[h][k] = dp[h][k] % MOD;
            } else {
                dp[h][k] = (dp[h - 1][k] * pat[k] * pat[W - k - 1]) +
                           (dp[h - 1][k - 1] * pat[k - 1] * pat[W - k - 1]) +
                           (dp[h - 1][k + 1] * pat[k] * pat[W - k - 2]);
                dp[h][k] = dp[h][k] % MOD;
            }
            // cout << "h:" << h << " k:" << k << " dp:" << dp[h][k] << endl;
        }
    }
    cout << dp[H][K - 1] << endl;
}