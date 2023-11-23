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

    dp[0][0] = A[0];
    dp[0][1] = 0;
    if(A[1] > A[0]) {
        dp[1][0] = A[1];
        dp[1][1] = 0;
    } else {
        dp[1][0] = A[0];
        dp[1][1] = 1;
    }
    long long maxN = 0;
    int maxi;
    rep(i, 0, 3) {
        if(i == 0) {
            long long GCDN = GCD(A[1], A[2]);
            if(GCDN > maxN) {
                maxN = GCDN;
                maxi = i;
            }
        }
        if(i == 1) {
            long long GCDN = GCD(A[0], A[2]);
            if(GCDN > maxN) {
                maxN = GCDN;
                maxi = i;
            }
        }
        if(i == 2) {
            long long GCDN = GCD(A[0], A[1]);
            if(GCDN > maxN) {
                maxN = GCDN;
                maxi = i;
            }
        }
    }
    dp[2][0] = maxN;
    dp[2][1] = maxi;
    rep(i, 3, N) {
        long long oldGCD = GCD(dp[i - 1][0], A[dp[i - 1][1]]);
        long long newGCD = GCD(dp[i - 1][0], A[i]);
        // cout << oldGCD << endl;
        //     cout << newGCD<< endl;
        if(oldGCD > newGCD) {
            dp[i][0] = oldGCD;
            dp[i][1] = i;
        } else {
            dp[i][0] = newGCD;
            dp[i][1] = dp[i - 1][1];
        }
    }
    cout << dp[N - 1][0] << endl;
}