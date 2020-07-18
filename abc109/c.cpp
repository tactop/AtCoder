#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
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
    long long N, X;
    cin>>N>>X;
    vector<long long> ve(N);
    rep(i, 0, N) { cin >> ve[i]; }
    ve.push_back(X);
    sort(ve.begin(), ve.end());
    int gcd = ve[1] - ve[0];
    rep(i, 0, N) {
        long long sa = ve[i + 1] - ve[i];
        gcd = GCD(gcd, sa);
    }
    cout << gcd << endl;
}