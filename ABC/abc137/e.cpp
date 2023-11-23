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
using pint = pair<int, int>;
using Edge = pair<long long, pint>; //<cost,<u,v>>の形
vector<Edge> edges;

int N, M, P, s;
vector<long long> d;
vector<bool> neg;

//到達可能でNへの経路中に正の閉路がある場合にtrueを返す
bool large_path(int start) {
    rep(i, 0, N) { d[i] = -INF; }
    d[start] = 0LL;
    rep(i, 0, N) {
        rep(j, 0, M) {
            Edge e = edges[j];
            long long cost = e.first;
            int to = e.second.second;
            int fr = e.second.first;
            if(d[fr] != -INF && d[to] < d[fr] + cost) {
                d[to] = d[fr] + cost;
            }
        }
    }
    rep(i, 0, N) {
        rep(j, 0, M) {
            Edge e = edges[j];
            long long cost = e.first;
            int to = e.second.second;
            int fr = e.second.first;
            if(d[fr] != -INF && d[to] < d[fr] + cost) {
                d[to] = d[fr] + cost;
                neg[to] = true;
            }
            if(neg[fr]) {
                neg[to] = true;
            }
        }
    }
    return neg[N - 1];
}
int main() {
    cin >> N >> M >> P;
    s = 0;
    d.assign(N, 0);
    neg.assign(N, false);
    rep(i, 0, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back(make_pair(c - P, make_pair(a, b)));
    }
    if(large_path(s)) {
        cout << -1 << endl;
    } else {
        if(d[N - 1] < 0) {
            cout << 0 << endl;

        } else {
            cout << d[N - 1] << endl;
        }
    }
}
