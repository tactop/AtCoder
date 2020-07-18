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
    int P[30];
    rep(i, 0, N) { cin >> P[i]; }
    int res = 0;
    rep(i, 1, N - 1) {
        int a = P[i - 1];
        int b = P[i];
        int c = P[i + 1];
        if((a < b && b < c) || (a > b && b > c)) {
            res++;
        }
    }
    cout << res << endl;
}