#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}

int le[2100][2100];
int ri[2100][2100];
int up[2100][2100];
int dw[2100][2100];
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, 0, H) { cin >> S[i]; }
    rep(i, 0, H) {
        int tmp = 0;
        rep(j, 0, W) {
            if(S[i][j] == '.') {
                tmp++;
                le[i][j] = tmp;
            } else {
                tmp = 0;
                le[i][j] = 0;
            }
            //            cout<<le[i][j];
        }
        // cout<<endl;
    }
    rep(i, 0, H) {
        int tmp = 0;
        rep(t, 0, W) {
            int j = W - 1 - t;
            if(S[i][j] == '.') {
                tmp++;
                ri[i][j] = tmp;
            } else {
                tmp = 0;
                ri[i][j] = 0;
            }
        }
    }
    rep(i, 0, W) {
        int tmp = 0;
        rep(j, 0, H) {
            if(S[j][i] == '.') {
                tmp++;
                dw[j][i] = tmp;
            } else {
                tmp = 0;
                dw[j][i] = 0;
            }
        }
    }
    rep(i, 0, W) {
        int tmp = 0;
        rep(t, 0, H) {
            int j = H - 1 - t;
            if(S[j][i] == '.') {
                tmp++;
                up[j][i] = tmp;
            } else {
                tmp = 0;
                up[j][i] = 0;
            }
        }
    }
    int max = 0;
    rep(i, 0, H) {
        rep(j, 0, W) {
            // cout << up[i][j];
            int tot = le[i][j] + ri[i][j] + up[i][j] + dw[i][j] - 3;
            if(max < tot) {
                max = tot;
            }
        }
        // cout << endl;
    }
    cout << max << endl;
}