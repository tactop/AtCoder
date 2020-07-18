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

    rep(i, 0, N) {
        rep(sum, 0, W + 1) {
            if(sum - wv[i][0]>=0) {
                chmax(dp[i + 1][sum], dp[i][sum - wv[i][0]] + wv[i][1]);
            }
            chmax(dp[i + 1][sum], dp[i][sum]);
        }
    }

    cout << dp[N][W] << endl;
}
