#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
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
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<int> res(N);
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            int k1 = j - i;
            int k2 = abs(X - i) + 1 + abs(Y - j);
            int k3 = abs(Y - i) + 1 + abs(X - j);
            int k = min({k1, k2, k3});
            res[k]++;
        }
    }
    rep(i, 1, N) { cout << res[i] << endl; }
}
