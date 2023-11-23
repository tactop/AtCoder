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
const double pi = 3.14159265358979323846;

int main() {
    long double A, B, H, M;
    cin >> A >> B >> H >> M;
    long double time = 60.0 * H + M;
    long double t1 = pi * 2 * time / (60.0 * 12.0);
    long double t2 = pi * 2 * time / 60.0;
    long double xx = (sin(t1) * A - sin(t2) * B) * (sin(t1) * A - sin(t2) * B);
    long double yy = (cos(t1) * A - cos(t2) * B) * (cos(t1) * A - cos(t2) * B);
    long double res = sqrt(xx + yy);
    cout << setprecision(15)<<res << endl;
}
