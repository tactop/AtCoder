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
long long h[100010][3];
long long dp[100010][3];

int main() {
    int N;
    cin >> N;
    rep(i, 0, N) {
        rep(r, 0, 3) { cin >> h[i][r]; }
    }

    rep(i, 0, N) {
        rep(r, 0, 3) { dp[i][r] = 0; }
    }

    rep(i, 0, N) {
        rep(r, 0, 3) {
            rep(k, 0, 3) {
                if(r!=k){
                chmax(dp[i+1][k], dp[i][r]+h[i][r]);}
            }
        }
    }

    long long res = 0;
    for (int j = 0; j < 3; ++j) chmax(res, dp[N][j]);
    cout << res << endl;
}