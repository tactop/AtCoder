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
    int N;
    cin >> N;
    vector<int> a(N + 1);
    int tmp = 0;
    int sum = 0;
    rep(i, 0, N) {
        cin >> a[i];
        sum += abs(tmp - a[i]);
        tmp = a[i];
    }
    sum += abs(0 - a[N - 1]);
    int mae = 0;
    a[N] = 0;
    rep(i, 0, N) {
        int ato = a[i + 1];
        int t = sum - (abs(a[i] - mae)) - (abs(a[i] - ato)) + (abs(ato - mae));
        mae = a[i];
        cout << t << endl;
    }
}
