#include <algorithm>
#include <cmath>
#include <iomanip>
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
    int N;
    int d[51];
    cin >> N;
    rep(i, 0, N) { cin >> d[i]; }
    long long res = 0;
    rep(i, 0, N) {

        rep(r, i + 1, N) { res += d[i] * d[r]; }
    }
    cout << res << endl;
}