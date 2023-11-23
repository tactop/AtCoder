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
int N, M, Q;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
long long max(vector<int> v, int k, int m) {
    if(k == N) {
        long long ten = 0;
        // rep(i, 0, v.size()) { cout << v[i] << " "; }
        rep(i, 0, Q) {
            if(v[b[i] - 1] - v[a[i] - 1] == c[i]) {
                ten += d[i];
            }
        }
        // cout << ten << endl;
        return ten;
    } else {
        long long maxten = 0;
        rep(i, m, M + 1) {
            vector<int> v2;
            v2 = v;
            v2.push_back(i);
            long long ten = max(v2, k + 1, i);
            if(maxten < ten) {
                maxten = ten;
            }
        }
        return maxten;
    }
}
int main() {
    cin >> N >> M >> Q;
    a.assign(Q, 0);
    b.assign(Q, 0);
    c.assign(Q, 0);
    d.assign(Q, 0);
    rep(i, 0, Q) { cin >> a[i] >> b[i] >> c[i] >> d[i]; }
    vector<int> v;
    cout << max(v, 0, 1) << endl;
}
