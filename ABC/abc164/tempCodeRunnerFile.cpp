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
typedef pair<long long, pair<int, int>> P; //時間、<場所、金>
using Edge = pair<int, pair<long long, long long>>;
using Graph = vector<vector<Edge>>;

int N, M, S;
Graph G;

vector<vector<long long>> dijkstra(int st, vector<vector<long long>> d, int k) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(N, vector<long long>(3000, INF));
    if(k >= 3000) {
        k = 2999;
    }
    d[st][k] = 0LL;
    que.push(P(0LL, make_pair(st, k)));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second.first;
        int kane = p.second.second;
        if(d[v][kane] < p.first) {
            continue;
        }
        for(auto e : G[v]) {
            long long cost = e.second.first;
            long long time = e.second.second;
            if(kane - cost < 0) {
                continue;
            }
            if(kane > 2500 && cost < 0) {
                continue;
            }
            long long nexttime = d[v][kane] + time;
            long long nextkane = kane - cost;
            if(nextkane > 2500) {
                nextkane = 2999;
            }
            if(d[e.first][nextkane] > nexttime) {
                d[e.first][nextkane] = nexttime;
                que.push(P(d[e.first][nextkane], make_pair(e.first, nextkane)));
            }
        }
    }
    return d;
}
int main() {
    cin >> N >> M >> S;
    G.assign(N, vector<Edge>());
    rep(i, 0, M) {
        long long u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        G[u].push_back(make_pair(v, make_pair(a, b)));
        G[v].push_back(make_pair(u, make_pair(a, b)));
    }
    rep(i, 0, N) {
        long long c, d;
        cin >> c >> d;
        G[i].push_back(make_pair(i, make_pair(-c, d)));
    }
    vector<vector<long long>> di;
    di = dijkstra(0, di, S);
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
    rep(i, 1, N) {
        long long min = INF;
        rep(j, 0, 3000) {
            if(di[i][j] < min) {
                min = di[i][j];
            }
        }
        cout << min << endl;
    }
}
