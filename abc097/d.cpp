#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++)
            par[i] = i;
    }

    int
    root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if(par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x);      // xの根をrx
        int ry = root(y);      // yの根をry
        if(rx == ry)
            return; // xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] =
            ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
vector<int> p;
vector<int> q;
vector<vector<int>> G;
int main() {
    int N, M;
    cin >> N >> M;
    p.assign(N, 0);
    q.assign(N, 0);
    rep(i, 0, N) {
        cin >> p[i];
        p[i]--;
        q[p[i]]=i;
    }
    UnionFind tree(N);
    rep(i, 0, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        tree.unite(x, y);
    }
    int res = 0;
    rep(i, 0, N) {
        //cout << "root" << tree.root(i) << "," << tree.root(q[i])<<endl;
        if(tree.same(i, q[i])) {
            res++;
        } 
    }
    cout << res << endl;
}
