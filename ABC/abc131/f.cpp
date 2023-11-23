#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
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

int main() {
    long long N;
    cin >> N;
    vector<long long> x(N), y(N);
    rep(i, 0, N) { cin >> x[i] >> y[i]; }
    long long MAX = 110000;
    UnionFind uf(MAX * 2);
    rep(i, 0, N) { uf.merge(x[i], (MAX + y[i])); }
    map<int, long long> mx, my;
    rep(i, 0, MAX) { mx[uf.root(i)]++; }
    rep(i, MAX, MAX * 2) { my[uf.root(i)]++; }
    long long res = 0;
    rep(i, 0, MAX * 2) { res += mx[i] * my[i]; }
    cout << res - N << endl;
}