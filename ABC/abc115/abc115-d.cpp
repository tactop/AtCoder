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
int N, X;
long long dp[60][60];
long long BG[60][2];

int main() {
    int N, X;
    cin >> N >> X;

    BG[0][0] = 1;
    BG[0][1] = 1;
    rep(i, 1, N + 1) {
        BG[i][0] = BG[i - 1][0] * 2 + 3;
        BG[i][1] = BG[i - 1][1] * 2 + 1;
    }
    cout<<BG[N][0]<<endl;
    cout<<BG[N][1]<<endl;
    rep(i, 1, N + 1) {
        rep(r, 1, X + 1) {
            if(BG[i][0] <= r) {
                dp[i][r] = BG[i][1];
                continue;
            }
            if(r == 1) {
                dp[i][r] = 0;
            } else if(r <= 1 + BG[i - 1][0]) {
                dp[i][r] = dp[i - 1][r - 1];
            } else if(r == 2 + BG[i - 1][0]) {
                dp[i][r] = BG[i - 1][1] + 1;
            } else if(r <= 2 + BG[i - 1][0] * 2) {
                dp[i][r] = BG[i - 1][1] + 1 + dp[i - 1][r - 2 - BG[i - 1][0]];
            } else {
                dp[i][r] = BG[i][1];
            }
        }
    }

    cout << dp[N][X] << endl;
}
