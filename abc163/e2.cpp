#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
long long M = 1000000007;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long N, K;
    cin >> N >> K;
    long long sum = 0;
    vector<long long> mo(K + 1);
    rep(i, 0, K) {
        long long t = K - i;
        long long a = K / t;
        mo[t] = modpow(K / t, N, M);
        rep(j, 2, a + 1) {
            mo[t] -= mo[j * t];
            mo[t] %= M;
        }
    }
    rep(i, 1, K + 1) {
        // cout << mo[i] << endl;
        long long p = mo[i] * i % M;
        sum = (sum + p) % M;
    }
    cout << sum << endl;
}
