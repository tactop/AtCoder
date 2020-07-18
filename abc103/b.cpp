#include <algorithm>
#include <cmath>
#include <iostream>
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
const int MOD = 1000000007;
int main() {
    int N, L;
    cin >> N >> L;
    int azi = 0;
    rep(i, 1, N + 1) { azi += L + i - 1; }
    int min = 100000;
    int res;
    rep(i, 1, N + 1) {
        int azi2 = 0;
        rep(r, 1, N + 1) {
            if(i != r) {
                azi2 += L + r - 1;
            }
        }
        if(abs(azi - azi2) < min) {
            min = abs(azi - azi2);
            res=azi2;
        }
    }
    cout << res << endl;
}