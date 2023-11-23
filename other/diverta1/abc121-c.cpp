#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
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
    string S[10010];
    rep(i, 0, N) { cin >> S[i]; }
    int A = 0, B = 0, kihon = 0;
    int arisuu = 0;
    rep(i, 0, N) {
        int size = S[i].size();
        int ari = false;
        if(S[i][0] == 'B') {
            B++;
            ari = true;
        }
        if(S[i][size - 1] == 'A') {
            A++;
            ari = true;
        }
        if(ari) {
            arisuu++;
        }
        int flg = 0;
        rep(r, 0, size) {

            if(S[i][r] == 'A') {
                flg = 1;
            } else if(flg == 1 && S[i][r] == 'B') {
                kihon++;
                flg = 0;
            } else {
                flg = 0;
            }
        }
    }
    int res = kihon + min({A, B});
    if(arisuu > 0 && A == arisuu && B == arisuu) {
        res--;
    }
    cout << res << endl;
}