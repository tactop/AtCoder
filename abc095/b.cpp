#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
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
int rui(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return rui(a, b - 1) * a;
}
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> m(N);

    rep(i, 0, N) {
        cin >> m[i];
        X -= m[i];
    }
    int mi = *min_element(m.begin(), m.end());
    cout << N + X / mi << endl;
}