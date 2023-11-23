#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
const int MAX = 2000000;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> bit(62);
    rep(i, 0, 62) { bit[i] = 0; }
    rep(i, 0, N) { cin >> A[i]; }
    rep(r, 0, N) {
        for(long long i = 0; i < 62; ++i) {
            if(A[r] & ((long long)1 << i)) { // i が bit に入るかどうか
                bit[i]++;
            }
        }
    }
    long long ans = 0;
    for(long long i = 0; i < 62; ++i) {
        //  cout << "i;" << i << ",bit[i]:" << bit[i] << endl;
        long long po = (long long)1 << i;
        long long ko = bit[i] * (N - bit[i]);
        po = po % MOD;
        ko = ko % MOD;
        ans += po * ko;
        ans = ans % MOD;
    }
    cout << ans << endl;
}
