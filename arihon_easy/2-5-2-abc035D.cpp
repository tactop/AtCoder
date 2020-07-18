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
typedef pair<long long, int> P;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
int N, M, T;
Graph G;
Graph G2;
vector<long long> A;
vector<long long> dijkstra(int st, Graph g, vector<long long> d) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(N, INF);
    d[st] = 0LL;
    que.push(P(0LL, st));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) {
            continue;
        }
        for(auto e : g[v]) {
            int to = e.first;
            int cost = e.second;
            if(d[to] > d[v] + cost) {
                d[to] = d[v] + cost;
                que.push(P(d[to], to));
            }
        }
    }
    return d;
}
int main() {
    cin >> N >> M >> T;
    A.assign(N, 0);
    rep(i, 0, N) { cin >> A[i]; }
    G.assign(N, vector<Edge>());
    G2.assign(N, vector<Edge>());
    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
        G2[b].push_back(make_pair(a, c));
    }
    vector<long long> iki;
    vector<long long> kaeri;
    iki = dijkstra(0, G, iki);
    kaeri = dijkstra(0, G2, kaeri);
    long long res = -INF;
    rep(i, 0, N) {
        if(iki[i] + kaeri[i] <= T) {
            long long t = 1LL * (T - (iki[i] + kaeri[i])) * A[i];
            if(res < t) {
                res = t;
            }
        }
    }
    cout << res << endl;
}
