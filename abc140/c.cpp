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
    vector<int> B(N);
    rep(i, 0, N - 1) { cin >> B[i]; }
    int res = B[0] + B[N - 2];
    rep(i, 0, N - 2) { res += min(B[i], B[i + 1]); }
    cout << res << endl;
}