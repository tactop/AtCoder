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
    long long N, K;
    cin >> N >> K;
    int A[2010];
    long long res = 0;
    long long dai = 0;
    long long syo = 0;
    rep(i, 0, N) { cin >> A[i]; }
    rep(i, 0, N) {
        rep(r, 0, N) {
            if(A[i] > A[r]) {
                if(i < r) {
                    dai++;
                }
                syo++;
            }
        }
    }

    res = (dai * K) % MOD;
    long long K1 = K;
    long long K2 = (K - 1);
    if(K % 2 == 0) {
        K1 = K1 / 2;
    } else {
        K2 = K2 / 2;
    }
    long long a = (syo * K1) % MOD;
    long long b = (a * K2) % MOD;
    res = (res + b) % MOD;
    cout << res << endl;
}