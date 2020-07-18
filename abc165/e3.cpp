//拡張ダイクストラ練習
//(https://atcoder.jp/contests/wupc2012-closed/tasks/wupc2012_5)
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
typedef pair<long long, pair<int, int>> P; //時間、<場所、mod>
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;

int N, M, s, t;
Graph G;

vector<vector<long long>> dijkstra(int st, vector<vector<long long>> d, int k) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(N, vector<long long>(k, INF));
    d[st][0] = 0LL;
    que.push(P(0LL, make_pair(st, 0)));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second.first;
        int vmod = p.second.second;
        if(d[v][vmod] < p.first) {
            continue;
        }
        for(auto e : G[v]) {
            long long cost = e.second;
            long long nemod = (d[v][vmod] + cost) % k;
            if(d[e.first][nemod] > d[v][vmod] + cost) {
                d[e.first][nemod] = d[v][vmod] + cost;
                if(e.first != N - 1) {
                    que.push(P(d[e.first][nemod], make_pair(e.first, nemod)));
                }
            }
        }
    }
    return d;
}
int main() {
    cin >> N >> M;
    G.assign(N, vector<Edge>());
    rep(i, 0, M) {
        long long u, v, a;
        cin >> u >> v >> a;
        G[u].push_back(make_pair(v, a));
        G[v].push_back(make_pair(u, a));
    }
    vector<vector<long long>> mod4;
    mod4 = dijkstra(s, mod4, 4);
    vector<vector<long long>> mod7;
    mod7 = dijkstra(s, mod7, 7);
    // cout << "4" << endl;
    // rep(i, 0, N) {
    //     rep(j, 0, 4) { cout << mod4[i][j] << " "; }
    //     cout << endl;
    // }
    // cout << "7" << endl;
    // rep(i, 0, N) {
    //     rep(j, 0, 7) { cout << mod7[i][j] << " "; }
    //     cout << endl;
    // }
    cout << min(mod4[N - 1][0], mod7[N - 1][0]) << endl;
}
