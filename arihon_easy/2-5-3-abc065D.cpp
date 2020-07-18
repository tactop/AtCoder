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

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if(par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y)
            return false;
        if(par[x] > par[y])
            swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) { return -par[root(x)]; }
};
// Kruskal 法で使用する枝
using pint = pair<int, int>;
using Edge = pair<long long, pint>; //<cost,<u,v>>の形
vector<Edge> edges;
int N, M;

int main() {
    cin >> N;
    M = 0;
    vector<pair<int, int>> xy(N);
    vector<pair<int, int>> xi(N);
    vector<pair<int, int>> yi(N);
    rep(i, 0, N) {
        cin >> xy[i].first >> xy[i].second;
        xi[i] = make_pair(xy[i].first, i);
        yi[i] = make_pair(xy[i].second, i);
    }
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());
    rep(i, 0, N - 1) {

        long long u, v, w;
        u = xi[i].second;
        v = xi[i+1].second;
        w = abs(xi[i].first - xi[i+1].first);
        edges.push_back(make_pair(w, (make_pair(u, v))));
        M++;
    }
    rep(i, 0, N - 1) {
        long long u, v, w;
        u = yi[i].second;
        v = yi[i+1].second;
        w = abs(yi[i].first - yi[i+1].first);
        edges.push_back(make_pair(w, (make_pair(u, v))));
        M++;
    }
    //クラスカル法（Kruskal）
    sort(edges.begin(), edges.end()); // costが小さい順にソート
    UnionFind uf(N);
    long long res = 0LL;
    // rep(i, 0, M) {
    //     cout << edges[i].first << "," << edges[i].second.first << ","
    //          << edges[i].second.second << endl;
    // }
    rep(i, 0, M) {
        Edge e = edges[i];
        int a = e.second.first;
        int b = e.second.second;
        if(!uf.issame(a, b)) {
            uf.merge(a, b);
            res += e.first;
        }
    }
    cout << res << endl;
}
