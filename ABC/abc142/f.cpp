#include <algorithm>
#include <bitset>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;

// bit全探索的なDP
int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }
    int min = N + 1;
    vector<int> res;
    rep(i, 0, N) {
        vector<int> d(N, -1);
        vector<int> pre(N, -1);
        queue<int> q;
        q.push(i);
        d[i] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto n : G[v]) {
                if(d[n] == -1) {
                    d[n] = d[v] + 1;
                    pre[n] = v;
                    q.push(n);
                }
            }
        }
        rep(j, 0, N) {
            if(i == j || d[j] == -1) {
                continue;
            }
            for(auto n : G[j]) {
                if(n == i) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    int cur = j;
                    while(cur != i) {
                        tmp.push_back(cur);
                        cur = pre[cur];
                    }
                    if(min > tmp.size()) {
                        min = tmp.size();
                        res = tmp;
                    }
                }
            }
        }
    }
    if(min == N + 1) {
        cout << -1 << endl;
    } else {
        cout << res.size() << endl;
        for(auto v : res) {
            cout << v + 1 << endl;
        }
    }
}