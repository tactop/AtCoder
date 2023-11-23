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

int main() {
    int H, W;
    cin >> H >> W;
    int kosuu = 0;
    queue<pair<int, int>> qe;

    rep(h, 1, H + 1) {
        rep(w, 1, W + 1) {
            cin >> hw[h][w];
            if(hw[h][w] == '#') {
                kosuu++;
                pair<int, int> p;
                p.first = h;
                p.second = w;
                qe.push(p);
            }
        }
    }
    int res = 0;
    while(kosuu < H * W) {
        char tmp[1010][1010];
        rep(h, 1, H + 1) {
            rep(w, 1, W + 1) { tmp[h][w] = hw[h][w]; }
        }

        rep(h, 1, H + 1) {
            rep(w, 1, W + 1) {

                if(hw[h][w] == '.') {
                    if(hw[h + 1][w] == '#' || hw[h - 1][w] == '#' ||
                       hw[h][w + 1] == '#' || hw[h][w - 1] == '#') {
                        tmp[h][w] = '#';
                        kosuu++;
                    }
                }
            }
        }
        res++;
        rep(h, 1, H + 1) {
            rep(w, 1, W + 1) { hw[h][w] = tmp[h][w]; }
        }
        // cout << endl;
        // rep(h, 1, H + 1) {
        //     rep(w, 1, W + 1) {
        //         cout<<hw[h][w];
        //     }
        //     cout<<endl;
        // }
    }

    cout << res << endl;
}