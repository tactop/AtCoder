//abc126d(https://atcoder.jp/contests/abc126/tasks/abc126_d)
#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

int N;
Graph G;
vector<int> res;
const long long INF = 1LL << 60;

void dfs(int v, int p, int c) {
    res[v] = c;
    for(auto e : G[v]) {
        if(e.first == p)
            continue;
        if(e.second%2==1)
            dfs(e.first, v, 1 - c);
        else
            dfs(e.first, v, c);
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
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    res.assign(N, 0);
    dfs(0, -1, 1);
    for (auto v : res) cout << v << endl;
}