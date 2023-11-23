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
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int res = 0;
    rep(a, 0, N + 1) {
        rep(b, 0, N - R * a + 1) {
            int nokori = N - (R * a) - (G * b);
            if(nokori >= 0 && nokori % B == 0) {
                // cout << "nokori" << nokori << endl;
                res++;
                // cout << a << "," << b << "," << nokori / B << endl;
            }
        }
    }
    cout << res << endl;
}