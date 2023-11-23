#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
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
int main() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<pair<int, int>> xy(H * W + 1);
    rep(i, 0, H) {
        rep(j, 0, W) {
            int a;
            cin >> a;
            xy[a] = make_pair(i, j);
        }
    }
    vector<int> dp(H * W + 1);
    rep(i, 1, H * W + 1) {
        if(i <= D) {
            dp[i] = 0;
        } else {
            dp[i] = dp[i - D] + abs(xy[i].first - xy[i - D].first) +
                    abs(xy[i].second - xy[i - D].second);
        }
    }
    int Q;
    cin >> Q;
    rep(i, 0, Q) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l] << endl;
    }
}
