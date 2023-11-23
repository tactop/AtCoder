#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
#define vein(v, n)                                                             \
    v.assign(n, 0);                                                            \
    for(int i = 0; i < n; i++) {                                               \
        cin >> v[i];                                                           \
    }
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, pair<int, int>> pp;
const long long INF = 1LL << 60;
int w, h, n;

//座標圧縮
int compress(vector<int> &ve1, vector<int> &ve2, int W) {
    vector<int> ves;
    rep(i, 0, n) {
        ves.push_back(ve1[i]);
        if(ve1[i] > 0) {
            ves.push_back(ve1[i] - 1);
        }
        ves.push_back(ve2[i] - 1);
        if(ve2[i] < W) {
            ves.push_back(ve2[i]);
        }
    }
    sort(ves.begin(), ves.end());
    ves.erase(unique(ves.begin(), ves.end()), ves.end());
    rep(i, 0, n) {
        ve1[i] = lower_bound(ves.begin(), ves.end(), ve1[i]) - ves.begin();
        ve2[i] = lower_bound(ves.begin(), ves.end(), ve2[i]) - ves.begin();
    }
    return ves.size();
}
int main() {

    vector<int> x1;
    vector<int> x2;
    vector<int> y1;
    vector<int> y2;
    cin >> w >> h >> n;
    x1.assign(n, 0);
    x2.assign(n, 0);
    y1.assign(n, 0);
    y2.assign(n, 0);
    rep(i, 0, n) { cin >> x1[i] >> y1[i] >> x2[i] >> y2[i]; }
    int aw = compress(x1, x2, w);
    int ah = compress(y1, y2, h);
    vector<vector<int>> newmap;
    newmap.assign(ah, vector<int>(aw));
    // mapを塗る。純粋にやったら間に合わない
    // rep(i, 0, n) {
    //     rep(a, x1[i], x2[i]) {
    //         rep(b, y1[i], y2[i]) { newmap[b][a] = 1; }
    //     }
    // }
    //いもす法
    rep(i, 0, n) {
        newmap[y1[i]][x1[i]]++;
        if(x2[i] < aw) {
            newmap[y1[i]][x2[i]]--;
        }
        if(y2[i] < ah) {
            newmap[y2[i]][x1[i]]--;
        }

        if(x2[i] < aw && y2[i] < ah) {
            newmap[y2[i]][x2[i]]++;
        }
    }
    rep(i, 0, ah) {
        rep(j, 1, aw) { newmap[i][j] += newmap[i][j - 1]; }
    }
    rep(i, 1, ah) {
        rep(j, 0, aw) { newmap[i][j] += newmap[i - 1][j]; }
    }
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int c = 1; //色の種類+1
    rep(i, 0, ah) {
        rep(j, 0, aw) {
            if(newmap[i][j] != 0) {
                continue;
            }
            c++;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            newmap[i][j] = c;
            while(!q.empty()) {
                int x = q.front().second, y = q.front().first;
                q.pop();
                for(int l = 0; l < 4; l++) {
                    int xx = x + dx[l], yy = y + dy[l];
                    if(xx < 0 || xx >= aw || yy < 0 || yy >= ah)
                        continue;
                    if(newmap[yy][xx] == 0) {
                        q.push(make_pair(yy, xx));
                        newmap[yy][xx] = c;
                    }
                }
            }
        }
    }
    // rep(i, 0, ah) {
    //     rep(j, 0, aw) { cout << newmap[i][j] << " "; }
    //     cout << endl;
    // }
    cout << c - 1 << endl;
}