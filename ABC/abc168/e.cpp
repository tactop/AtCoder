#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 50;

const int MOD = 1000000007;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
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
pair<long long, long long> yaku(long long a, long long b) {
    int f = 1;
    if(a * b < 0) {
        f = -1;
    }
    a = abs(a);
    b = abs(b);
    long long g = GCD(a, b);
    a /= g;
    b /= g;
    return (make_pair(f * a, b));
}
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    rep(i, 0, N) { cin >> A[i] >> B[i]; }
    long long res = 0;
    map<pair<long long, long long>, long long> m;
    m[yaku(A[0], B[0])] = 1;
    res++;
    rep(i, 1, N) {
        pair<long long, long long> p = yaku(-B[i], A[i]);
        cout << "p1:" << p.first << "," << p.second << endl;
        long long k = 0;

        if(m[p] > 0) {
            k = m[p];
        }
        cout << k << "," << modpow(2, i - k, MOD) << endl;
        res = (res + modpow(2, i - k, MOD)) % MOD;
        pair<long long, long long> p2 = yaku(A[i], B[i]);
        if(m[p2] > 0) {
            m[p2]++;
            cout << "a" << endl;
        } else {
            m[p2] = 1;
        }
        cout << "p2:" << p2.first << "," << p2.second << endl;
    }
    cout << res << endl;
}
