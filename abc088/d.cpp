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
const int INTINF = 1 << 20;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int H, W;
    cin >> H >> W;
    string map[55];
    int saitan[55][55];
    int shiro = 0;
    rep(i, 0, H) {
        cin >> map[i];
        rep(j, 0, W) {
            saitan[i][j] = -1;
            if(map[i][j] == '.') {
                shiro++;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    saitan[0][0] = 1;
    while(q.size() > 0) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        if(tx > 0 && map[tx - 1][ty] == '.' && saitan[tx - 1][ty] == -1) {
            saitan[tx - 1][ty] = saitan[tx][ty] + 1;
            q.push(make_pair(tx - 1, ty));
        }
        if(tx < H - 1 && map[tx + 1][ty] == '.' && saitan[tx + 1][ty] == -1) {
            saitan[tx + 1][ty] = saitan[tx][ty] + 1;
            q.push(make_pair(tx + 1, ty));
        }
        if(ty > 0 && map[tx][ty - 1] == '.' && saitan[tx][ty - 1] == -1) {
            saitan[tx][ty - 1] = saitan[tx][ty] + 1;
            q.push(make_pair(tx, ty - 1));
        }
        if(ty < W- 1 && map[tx][ty + 1] == '.' && saitan[tx][ty + 1] == -1) {
            saitan[tx][ty + 1] = saitan[tx][ty] + 1;
            q.push(make_pair(tx, ty + 1));
        }
    }
    // rep(i, 0, H) {
    //     rep(j, 0, W) { cout << saitan[i][j] << " "; }
    //     cout << endl;
    // }
    if(saitan[H - 1][W - 1] == -1) {
        cout << -1 << endl;
    } else {
        cout << shiro - saitan[H - 1][W - 1] << endl;
    }
}
