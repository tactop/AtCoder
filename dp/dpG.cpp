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
int N, M;
vector<vector<int>> G;
int dp[100100];

int rec(int v) {
    if(dp[v] != -1) {
        return dp[v];
    }
    int res = 0;
    for(auto nv : G[v]) {
        chmax(res, rec(nv) + 1);
    }
    return dp[v] = res;
}

int main() {

    cin >> N >> M;
    G.assign(N, vector<int>());
    rep(i, 0, M) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        G[x].push_back(y);
    }

    rep(i, 0, N) dp[i] = -1;

    int res = 0;
    rep(i, 0, N) chmax(res, rec(i));
    cout << res << endl;
}
