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
int N;
long long wv[110][2];
long long dp[110][100010];

int main() {
    int N, W;
    cin >> N >> W;
    rep(i, 0, N) {
        rep(r, 0, 2) { cin >> wv[i][r]; }
    }
    rep(i, 0, N+1) {
        rep(r, 0, 100010) { dp[i][r] = INF; }
    }

    dp[0][0]=0;
    rep(i, 0, N) {
        rep(sumV, 0, 100010) {
            if(sumV - wv[i][1] >= 0) {
                chmin(dp[i + 1][sumV], dp[i][sumV - wv[i][1]] + wv[i][0]);
            }
            chmin(dp[i + 1][sumV], dp[i][sumV]);
        }
    }
    long long res;
    rep(sumV, 0, 100010) {
        if(dp[N][sumV] <= W) {
            res = sumV;
        }
    }

    cout << res << endl;
}
