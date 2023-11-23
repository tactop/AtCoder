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
    int N;
    cin >> N;
    int count = 0;
    rep(i, 1, N + 1) {
        int yaku = 0;
        rep(r, 1, N + 1) {
            if(i % r == 0) {
                yaku++;
            }
        }
        if(i % 2 == 1 && yaku == 8) {
            count++;
        }
    }
    cout << count << endl;
}