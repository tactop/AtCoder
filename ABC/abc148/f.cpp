#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;

int N, u, v;
Graph G;
vector<int> res;
const long long INF = 1LL << 60;

void dfs(int s, int p, vector<int> &d) {

    for(auto e : G[s]) {
        if(e == p) {
            continue;
        } else {
            // cout << s << "," << e << endl;
            d[e] = d[s] + 1;
            dfs(e, s, d);
        }
    }
}

int main() {
    cin >> N >> u >> v;
    u--;
    v--;
    G.assign(N, vector<int>());
    rep(i, 0, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> uu(N);
    vector<int> vv(N);
    uu[u] = 0;
    vv[v] = 0;
    dfs(u, -1, uu);
    dfs(v, -1, vv);
    int max = 0;
    rep(i, 0, N) {
        if(uu[i] < vv[i]) {
            if(max < vv[i]) {
                max = vv[i];
            }
        }
    }
    cout << max - 1 << endl;
}