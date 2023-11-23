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
int d[510][510];
int c[510][510];
int main() {
    int N, C;
    cin >> N >> C;
    rep(i, 0, C) {
        rep(j, 0, C) { cin >> d[i][j]; }
    }
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<int>> v(3);
    rep(i, 0, N) {
        rep(j, 0, N) { v[(i + j) % 3].push_back(c[i][j]); }
    }
    int res[3][3][2];
    rep(i, 0, 3) {
        rep(j, 0, 3) { res[i][j][0] = 1000000; }
    }

    // rep(i, 0, 3) {
    //     cout << "i=" << i << endl;
    //     for(auto vv : v[i]) {
    //         cout << vv << ",";
    //     }
    //     cout << endl;
    // }
    rep(n, 0, 3) {
        int dc;
        rep(t, 0, C) {
            int dsum = 0;
            for(auto f : v[n]) {
                if(t != f) {
                    dsum += d[f][t];
                }
            }
            rep(i, 0, 3) {
                if(res[n][i][0] > dsum) {
                    if(i != 2) {
                        res[n][2][0] = res[n][1][0];
                        res[n][2][1] = res[n][1][1];
                    }
                    if(i == 0) {
                        res[n][1][0] = res[n][0][0];
                        res[n][1][1] = res[n][0][1];
                    }
                    res[n][i][0] = dsum;
                    res[n][i][1] = t;
                    break;
                }
            }
        }
        // cout << "n=" << n << endl;
        // rep(i, 0, 3) {
        //     cout << "t" << res[n][i][0] << "," << res[n][i][1] << endl;
        // }
    }
    int ans = 1000000;
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            rep(k, 0, 3) {
                if(res[0][i][1] == res[1][j][1] ||
                   res[2][k][1] == res[1][j][1] ||
                   res[2][k][1] == res[0][i][1]) {
                    continue;
                }
                // cout << res[0][i][0] << "," << res[1][j][0] << ","
                //      << res[2][k][0] << endl;
                ans = min(ans, res[0][i][0] + res[1][j][0] + res[2][k][0]);
            }
        }
    }
    cout << ans << endl;
}
