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
    int res = 10000000;
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);

    int mina = 10000000;
    rep(i, 0, A) {
        cin >> a[i];
        chmin(mina, a[i]);
    }
    int minb = 10000000;
    rep(i, 0, B) {
        cin >> b[i];
        chmin(minb, b[i]);
    }
    chmin(res, mina + minb);
    vector<int> x(M);
    vector<int> y(M);
    vector<int> c(M);
    rep(i, 0, M) {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
        chmin(res, (a[x[i]] + b[y[i]] - c[i]));
    }
    cout << res << endl;
}