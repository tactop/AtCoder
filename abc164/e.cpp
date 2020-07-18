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
const long long INF = 1LL << 50;
const int ININF = 1000000;
using pint = pair<int, int>;
using Edge = pair<long long, pint>; //<cost,<u,v>>の形
vector<Edge> edges;

int N, M, S;
vector<vector<long long>> d;
vector<vector<long long>> co;
int main() {
    cin >> N >> M >> S;
    d.assign(N, vector<long long>(N));
    rep(i, 0, N) {
        rep(j, 0, N) {
            if(i == j) {
                d[i][j] = 0LL;
            } else {
                d[i][j] = INF;
            }
        }
    }
    rep(i, 0, N) {
        rep(j, 0, N) {
            if(i == j) {
                co[i][j] = 0LL;
            } else {
                co[i][j] = INF;
            }
        }
    }
    rep(i, 0, M) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        d[u][v] = a;
        d[v][u] = a;
        co[u][v] = a;
        co[v][u] = a;
    }
    rep(k, 0, N) {
        rep(i, 0, N) {
            rep(j, 0, N) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
        }
    }
    long long res = INF;
    // rep(i, 0, N) {
    //     rep(j, 0, N) { cout << d[i][j] << " "; }
    //     cout << endl;
    // }
    rep(i, 0, N) {
        long long max = 0;
        rep(j, 0, N) {
            if(max < d[i][j]) {
                max = d[i][j];
            }
        }
        if(res > max) {
            res = max;
        }
    }
    cout << res << endl;
}
