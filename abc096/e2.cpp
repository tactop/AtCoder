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
const int MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    if(N == 1) {
        cout << 1 << endl;
    } else {
        long long s = GCD(A[0], A[1]);
        rep(i, 1, N - 1) { s = GCD(A[i], A[i + 1]); }
        long long l = A[0] * A[1] / s;
        l %= MOD;
        rep(i, 1, N - 1) {
            l = A[i] * A[i + 1] / s;
            l %= MOD;
        }
          cout << s<< endl;
        cout << l << endl;
        long long sum = 0;
        rep(i, 0, N) {
            sum += l / A[i];
            sum %= MOD;
        }
        cout << sum << endl;
    }
}
