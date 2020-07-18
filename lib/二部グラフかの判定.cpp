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

using Graph = vector<vector<int>>;
int N, M;
Graph G;
vector<int> color; //色（1or-1）
//二部グラフかの判定（連結の場合）
bool dfs(int v, int c) {
    color[v] = c;
    for(auto e : G[v]) {
        //隣接している頂点が同じ色なら即false;
        if(color[e] == c) {
            return false;
        }
        //隣接している頂点が塗られていないなら塗る。falseだったらfalse返す。
        if(color[e] == 0 && !dfs(e, -c)) {
            return false;
        }
    }
    return true;
}
int main() {
    cin >> N >> M;
    G.assign(N, vector<int>());
    color.assign(N, 0);
    rep(i, 0, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //二部グラフかの判定（連結の場合）
    if(dfs(0, 1)) {
        int b = 0;
        int w = 0;
        rep(i, 0, N) {
            if(color[i] == 1) {
                b++;
            } else {
                w++;
            }
        }
        cout << 1LL * b * w - M << endl;
    } else {
        cout << 1LL * N * (N - 1) / 2 - M << endl;
    }
}
