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
    int N, K, R, S, P;
    string T;
    int res = 0;
    cin >> N >> K >> R >> S >> P >> T;
    vector<char> te(N);
    rep(i, 0, N) {
        if(i + 1 <= K) {
            if(T[i] == 'r') {
                res += P;
            } else if(T[i] == 's') {
                res += R;
            } else {
                res += S;
            }
            te[i] = T[i];
        } else {
            if(T[i] == 'r') {
                if(te[i - K] != 'r') {
                    res += P;
                    te[i] = T[i];
                } else {
                    if(i + K < N && T[i + K] == 's') {
                        te[i] = 'p';
                    } else {
                        te[i] = 's';
                    }
                }
            } else if(T[i] == 's') {
                if(te[i - K] != 's') {
                    res += R;
                    te[i] = T[i];
                } else {
                    if(i + K < N && T[i + K] == 'r') {
                        te[i] = 'p';
                    } else {
                        te[i] = 'r';
                    }
                }
            } else {
                if(te[i - K] != 'p') {
                    res += S;
                    te[i] = T[i];
                } else {
                    if(i + K < N && T[i + K] == 'r') {
                        te[i] = 's';
                    } else {
                        te[i] = 'r';
                    }
                }
            }
        }
        // cout << te[i] << "," << res << endl;
    }
    cout << res << endl;
}
