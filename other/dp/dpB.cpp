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
long long h[100010];
long long dp[100010];

int main() {
    int N, K;
    cin >> N >> K;
    rep(i, 0, N) cin >> h[i];

    rep(i, 0, N) dp[i] = INF;

    dp[0] = 0;
    rep(i, 0, N) {
        rep(r, 1, K+1) { chmin(dp[i + r], dp[i] + abs(h[i + r] - h[i])); }
    }

    cout << dp[N - 1] << endl;
}