#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
const int MAX = 2000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<pair<int, int>> pp;
    rep(i, 0, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        pp.emplace_back(a, b);
    }
    int K = 0;
    map<pair<int, int>, int> I;
    vector<int> cs(N, 0);

    vector<int> used(N, 0);
    queue<int> que;
    used[0] = 1;
    que.emplace(0);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        if(K < (int)G[v].size()) {
            K = G[v].size();
        }
        int cur = 1;
        for(int u : G[v]) {
            if(used[u])
                continue;
            if(cur == cs[v])
                cur++;
            cs[u] = I[make_pair(u, v)] = I[make_pair(v, u)] = cur++;
            used[u] = 1;
            que.emplace(u);
        }
    }

    cout << K << endl;
    for(auto p : pp)
        cout << I[p] << endl;
    return 0;
}