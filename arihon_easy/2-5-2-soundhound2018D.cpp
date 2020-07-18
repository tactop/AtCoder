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
using Edge = pair<int, pair<int, int>>;
using Graph = vector<vector<Edge>>;

int N, M, s, t;
Graph G;
vector<long long> res;

vector<long long> dijkstra(int st, vector<long long> d, int k) {
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
        for(auto e : G[v]) {
            int cost;
            if(k == 0) { //円を使う
                cost = e.second.first;
            }
            if(k == 1) { //スヌークを使う
                cost = e.second.second;
            }
            if(d[e.first] > d[v] + cost) {
                d[e.first] = d[v] + cost;
                que.push(P(d[e.first], e.first));
            }
        }
    }
    return d;
}
int main() {
    cin >> N >> M >> s >> t;
    s--;
    t--;
    G.assign(N, vector<Edge>());
    rep(i, 0, M) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        G[u].push_back(make_pair(v, make_pair(a, b)));
        G[v].push_back(make_pair(u, make_pair(a, b)));
    }

    vector<long long> enStoT;
    enStoT = dijkstra(s, enStoT, 0);
    vector<long long> snTtoS;
    snTtoS = dijkstra(t, snTtoS, 1);
    // rep(i, 0, N) { cout << "i:" << i << ",d:" << enStoT[i] << endl; }
    // rep(i, 0, N) { cout << "i:" << i << ",d:" << snTtoS[i] << endl; }
    res.assign(N, 0);
    res[N - 1] = enStoT[N - 1] + snTtoS[N - 1];
    rep(k, 0, N - 1) {
        int i = N - 2 - k;
        long long tmp = enStoT[i] + snTtoS[i];
        if(res[i + 1] > tmp) {
            res[i] = tmp;
        } else {
            res[i] = res[i + 1];
        }
    }
    rep(i, 0, N) { cout << 1000000000000000-res[i] << endl; }
}
