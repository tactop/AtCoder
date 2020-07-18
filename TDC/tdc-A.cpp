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
long long p[110];
long long dp[110][10010];

int main() {
    int N;
    cin >> N;
    rep(i, 0, N) { cin >> p[i]; }

    rep(i, 0, 110) {
        rep(r, 0, 10010) { dp[i][r] = 0; }
    }
    dp[0][0] = 1;

    rep(i, 0, N) {
        rep(sum, 0, 10010) {
            if(dp[i][sum] == 1) {
                dp[i + 1][sum + p[i]] = 1;
                dp[i + 1][sum] = 1;
            }
        }
    }
    int res = 0;
    rep(r, 0, 10010) {
        if(dp[N][r] == 1) {
            res++;
        }
    }

    cout << res << endl;
}
