#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
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
const int ININF = 1000000;

int main() {
    string hw[22];
    int H, W;
    cin >> H >> W;
    rep(i, 0, H) { cin >> hw[i]; }
    int res = 0;
    rep(i, 0, H) {
        rep(j, 0, W) {
            if(hw[i][j] == '#') {
                continue;
            }
            int d[22][22];
            rep(t, 0, H) {
                rep(s, 0, W) { d[t][s] = ININF; }
            }
            d[i][j] = 0;
            queue<pair<int, int>> que;

            que.push(make_pair(i, j));
            // BFS 開始 (キューが空になるまで探索を行う)
            while(!que.empty()) {
                pair<int, int> tmp = que.front();
                que.pop();
                int a = tmp.first;
                int b = tmp.second;
                int count = d[a][b];
                if(a != 0 && hw[a - 1][b] == '.' && d[a - 1][b] > count + 1) {
                    d[a - 1][b] = count + 1;
                    que.push(make_pair(a - 1, b));
                }
                if(b != 0 && hw[a][b - 1] == '.' && d[a][b - 1] > count + 1) {
                    d[a][b - 1] = count + 1;
                    que.push(make_pair(a, b - 1));
                }
                if(a != H - 1 && hw[a + 1][b] == '.' &&
                   d[a + 1][b] > count + 1) {
                    d[a + 1][b] = count + 1;
                    que.push(make_pair(a + 1, b));
                }
                if(b != W - 1 && hw[a][b + 1] == '.' &&
                   d[a][b + 1] > count + 1) {
                    d[a][b + 1] = count + 1;
                    que.push(make_pair(a, b + 1));
                }
            }
            int max = 0;
            rep(t, 0, H) {
                rep(s, 0, W) {
                    if(d[t][s] != ININF && d[t][s] > max) {
                        max = d[t][s];
                    }
                    // cout << d[t][s] << " ";
                }
                // cout << endl;
            }
            if(res < max) {
                res = max;
            }
        }
    }
    cout << res << endl;
}
