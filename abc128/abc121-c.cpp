#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <type_traits>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
double ruijo(double x, int n) {
    double res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
int intruijo(int x, int n) {
    int res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
int main() {
    int N, M;
    cin >> N >> M;
    int k[11];
    int s[11][11];
    int p[11];
    rep(i, 0, M) {
        cin >> k[i];
        rep(r, 0, k[i]) { cin >> s[i][r]; }
    }

    rep(i, 0, M) { cin >> p[i]; }

    int res = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for(int bit = 0; bit < (1 << N); ++bit) {
        int onR = 0;
        // cout << "bit" << bit << endl;
        rep(i, 0, M) {
            int on = 0;
            rep(r, 0, k[i]) {
                // cout << "s:" << s[i][r] << endl;
                if(bit & (1 << s[i][r] - 1)) {
                    on++;
                    // cout << i << "," << r << "," << bit << endl;
                }
            }
            // cout << "on" << on << endl;
            if(on % 2 == p[i]) {
                onR++;
            }
        }
        if(onR == M) {
            res++;
        }
    }
    cout << res << endl;
}