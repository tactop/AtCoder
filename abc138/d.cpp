#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
int N, Q;
Graph G;
vector<int> ten;
vector<int> res;
void dfs(int v, int pa, int c) {
   //  cout << v << "," << pa << "," << c << endl;
    res[v] = c + ten[v];
    for(auto e : G[v]) {
        if(e == pa) {
            continue;
        } else {
            dfs(e, v, res[v]);
        }
    }
}
int main() {
    cin >> N >> Q;
    G.assign(N, vector<int>());
    ten.assign(N, 0);
    res.assign(N, 0);
    rep(i, 0, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, 0, Q) {
        int p, x;
        cin >> p >> x;
        p--;
        ten[p] += x;
    }

    dfs(0, -1, 0);
    rep(i, 0, N) {
        cout << res[i];
        if(i != N-1)
            cout << " ";
    }
    cout<<endl;
}