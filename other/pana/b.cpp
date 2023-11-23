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
    long long H, W;
    cin >> H >> W;
    if(H == 1 || W == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(H % 2 == 0) {
        cout << H / 2 * W << endl;
    } else {
        if(W % 2 == 0) {
            cout << W / 2 * H << endl;
        } else {
            cout << ((H - 1) / 2 * W) + W / 2 + 1 << endl;
        }
    }
}