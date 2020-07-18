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

int N, M, L;
vector<vector<long long>> d;
vector<vector<long long>> d2;

int main() {
    cin >> N >> M >> L;
    d.assign(N, vector<long long>(N));
    d2.assign(N, vector<long long>(N));
    rep(i, 0, N) {
        rep(j, 0, N) {
            if(i == j) {
                d[i][j] = 0LL;
                d2[i][j] = 0LL;
            } else {
                d[i][j] = INF;
                d2[i][j] = INF;
            }
        }
    }
    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    int Q;
    cin >> Q;
    vector<int> s(Q);
    vector<int> t(Q);
    rep(i, 0, Q) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
    }
    rep(k, 0, N) {
        rep(i, 0, N) {
            rep(j, 0, N) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
        }
    }
    long long res = INF;
    // cout << "d" << endl;
    // rep(i, 0, N) {
    //     rep(j, 0, N) { cout << d[i][j] << " "; }
    //     cout << endl;
    // }
    rep(i, 0, N) {
        rep(j, 0, N) {
            if(i != j && L >= d[i][j]) {
                d2[i][j] = 1;
            }
        }
    }
    rep(k, 0, N) {
        rep(i, 0, N) {
            rep(j, 0, N) { d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]); }
        }
    }
    // cout << "d2" << endl;
    // rep(i, 0, N) {
    //     rep(j, 0, N) { cout << d2[i][j] << " "; }
    //     cout << endl;
    // }

    rep(i, 0, Q) {

        if(d2[s[i]][t[i]] != INF) {
            cout << d2[s[i]][t[i]] - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
