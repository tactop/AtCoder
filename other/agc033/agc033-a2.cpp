#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
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
int N;
char hw[1010][1010];
int kaisuu[1010][1010];

int main() {
    int H, W;
    cin >> H >> W;
    int kosuu = 0;
    queue<pair<int, int>> qe;
    rep(h, 0, 1010) {
        rep(w, 0, 1010) { kaisuu[h][w] = 10000000; }
    }
    rep(h, 1, H + 1) {
        rep(w, 1, W + 1) {
            cin >> hw[h][w];
            if(hw[h][w] == '#') {
                kosuu++;
                kaisuu[h][w] = 0;
            }
        }
    }
    while(kosuu < H * W) {

        rep(h, 1, H + 1) {
            rep(w, 1, W + 1) {

                if(hw[h][w] == '.') {
                    if(hw[h + 1][w] == '#' || hw[h - 1][w] == '#' ||
                       hw[h][w + 1] == '#' || hw[h][w - 1] == '#') {
                        int minkaisuu = 10000000;
                        chmin(minkaisuu, kaisuu[h + 1][w]);
                        chmin(minkaisuu, kaisuu[h - 1][w]);
                        chmin(minkaisuu, kaisuu[h][w + 1]);
                        chmin(minkaisuu, kaisuu[h][w - 1]);
                        int newkaisuu = 1 + minkaisuu;
                        kaisuu[h][w] = newkaisuu;
                        hw[h][w] = '#';
                        kosuu++;
                    }
                }
            }
        }
    }
    // cout << endl;
    // rep(h, 1, H + 1) {
    //     rep(w, 1, W + 1) { cout << kaisuu[h][w]; }
    //     cout << endl;
    // }

    int max = 0;
    rep(h, 1, H + 1) {
        rep(w, 1, W + 1) { chmax(max, kaisuu[h][w]); }
    }
    cout << max << endl;
}