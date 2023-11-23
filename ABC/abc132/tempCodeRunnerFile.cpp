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
const int ININF = 1000000;

int main() {
    int N, M;
    cin >> N >> M;
    Graph G;
    G.assign(N, vector<int>());
    rep(i, 0, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<int> v;
    v.push_back(ININF);
    v.push_back(ININF);
    v.push_back(ININF);
    Graph d;
    d.assign(N, v);

    d[s][0] = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(s, 0));
    // BFS 開始 (キューが空になるまで探索を行う)
    while(!que.empty()) {
        pair<int, int> tmp = que.front();
        que.pop();
        int a = tmp.first;
        int b = tmp.second;
        int neb = (b + 1) % 3;
        int count = d[a][b];

        for(auto ne : G[a]) {
            if(d[ne][neb] > count + 1) {
                d[ne][neb] = count + 1;
                que.push(make_pair(ne, neb));
            }
        }
    }
    if(d[t][0] == ININF) {
        cout << -1 << endl;
    } else {
        cout << d[t][0] / 3 << endl;
    }
}
