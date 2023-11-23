#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
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
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

int N;
Graph G;
vector<int> res;

void dfs(int v, int p, int c) {
    for(auto e : G[v]) {
        if(e.first == p)
            continue;
        if(e.second % 2 == 0) {
            res[e.first] = c;
        } else {
            res[e.first] =1-c;
        }
        dfs(e.first, v, res[e.first]);
    }
}
int main() {
    cin >> N;
    G.assign(N, vector<Edge>());
    rep(i, 0, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    res.assign(N, 0);
    res[0]=1;
    dfs(0, -1, 1);
    rep(i, 0, N) { cout << res[i] << endl; }
}
