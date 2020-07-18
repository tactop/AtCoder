#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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
int main() {
    int N;
    int T, A;
    cin >> N >> T >> A;
    int h[1010];
    rep(i, 0, N) { cin >> h[i]; }
    double min = 100000.0;
    int res;
    rep(i, 0, N) {
        double dif = abs((double)A - ((double)T - (double)h[i] * 0.006));
        if(min > dif) {
            res = i + 1;
            min = dif;
        }
    }
    cout << res << endl;
}