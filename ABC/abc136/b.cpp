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
    int res = 0;
    rep(i, 0, N) {
        int a = N - i;
        if((1 <= a && a <= 9) || (100 <= a && a <= 999) ||
           (10000 <= a && a <= 99999)) {
            res++;
        }
    }
    cout << res << endl;
}