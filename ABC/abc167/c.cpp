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
int N, M, X;

vector<int> c;
vector<vector<int>> a;
long long minkane(vector<int> v, int k) {
    if(k == N) {
        long long ret = 0LL;
        vector<int> rikai(M);
        rep(i, 0, N) {
            if(v[i] == 1) {
                ret += c[i];
                rep(j, 0, M) { rikai[j] += a[i][j]; }
            }
        }
        bool ok = true;
        rep(i, 0, M) {
            if(X > rikai[i])
                ok = false;
        }
        if(ok) {
            return ret;
        } else {
            return INF;
        }
    } else {
        vector<int> r1 = v;
        vector<int> r2 = v;
        r1.push_back(1);
        r2.push_back(0);
        return min(minkane(r1, k + 1), minkane(r2, k + 1));
    }
}
int main() {
    cin >> N >> M >> X;
    a.assign(N, vector<int>(M));
    c.assign(N, 0);
    rep(i, 0, N) {
        cin >> c[i];
        rep(j, 0, M) { cin >> a[i][j]; }
    }
    vector<int> v;
    long long res = minkane(v, 0);
    if(res == INF) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}
