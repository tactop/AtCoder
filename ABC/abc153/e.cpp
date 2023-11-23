#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    int H, N;
    cin >> H >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    rep(i, 0, N) { cin >> A[i] >> B[i]; }
    vector<long long> dp(H + 1, INF);
    dp[0] = 0;
    rep(i, 1, H + 1) {
        rep(n, 0, N) {
            if(i - A[n] > 0) {
                dp[i] = min(dp[i], dp[i - A[n]] + B[n]);
            } else {
                dp[i] = min(dp[i], B[n]);
            }
        }
      //  cout << dp[i] << endl;
    }
    cout << dp[H] << endl;
}
