#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
int N;
long long A[100010];
long long dp[100010][2];
int GCD(long long x, long long y) { return x ? GCD(y % x, x) : y; }
int main() {
    int N;
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    int odd = 1;
    int zero = 0;
    rep(i, 0, N) {
        if(A[i] < 0) {
            odd *= -1;
        } else if(A[i] == 0) {
            zero = 1;
        }
    }
    long long res = 0;
    if(odd == 1 || zero == 1) {
        rep(i, 0, N) res += abs(A[i]);
    } else {
        long long min = INF;
        rep(i, 0, N) {
            if(abs(A[i]) < min) {
                min = abs(A[i]);
            }
        }
        rep(i, 0, N) res += abs(A[i]);
        res -= min;
        res -= min;
    }
    cout << res << endl;
}