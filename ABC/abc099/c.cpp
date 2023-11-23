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

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}

int main() {
    int N;
    cin >> N;
    int a = 1;
    int b = 1;
    vector<int> v;
    v.push_back(1);
    rep(i, 0, 7) {
        a *= 6;
        b *= 9;
        if(a < 100000) {
            v.push_back(a);
        }
        if(b < 100000) {
            v.push_back(b);
        }
    }
    vector<int> dp(1000000, 100000);
    dp[0]=0;
    rep(i, 0, N) {
        for(auto tv : v) {
            dp[i + tv] = min(dp[i + tv], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
}
