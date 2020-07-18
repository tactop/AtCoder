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
    int A, B, K;
    cin >> A >> B >> K;
    if(A + K - 1 >= B - K + 1) {
        rep(i, A, B + 1) { cout << i << endl; }
    } else {
        rep(i, A, A + K) { cout << i << endl; }
        rep(i, B - K + 1, B + 1) { cout << i << endl; }
    }
}