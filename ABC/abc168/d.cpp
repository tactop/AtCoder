#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;

int N, M;
Graph G;
vector<int> res;
const long long INF = 1LL << 60;

int main() {
    cin >> N >> M;
    G.assign(N, vector<int>());
    rep(i, 0, M) {

        int a, b;
        cin >> a >> b;
        ;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while(!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for(int nv : G[v]) {
            if(dist[nv] != -1)
                continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    vector<int> res(N);
    cout << "Yes" << endl;
    rep(i, 1, N) {
        for(int t : G[i]) {
            if(dist[t] == dist[i] - 1) {
                res[i] = t + 1;
                break;
            }
        }
    }
    rep(i, 1, N) { cout << res[i] << endl; }
}
