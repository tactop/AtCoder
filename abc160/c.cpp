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
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    long long K, N;
    cin >> K >> N;
    vector<long long> a(N);
    rep(i, 0, N) { cin >> a[i]; }
    long long min = a[N - 1] - a[0];
    rep(i, 1, N) {
        if(K - (a[i] - a[i - 1]) < min) {
            min = K - a[i] + a[i - 1];
        }
    }
    cout << min << endl;
}
