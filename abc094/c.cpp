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
    vector<int> x(N);
    vector<int> sortx(N);
    rep(i, 0, N) {
        cin >> x[i];
        sortx[i] = x[i];
    }
    sort(sortx.begin(), sortx.end());
    int mae = sortx[N / 2 - 1];
    int ato = sortx[N / 2];
    // cout << mae << ato << endl;
    rep(i, 0, N) {
        if(x[i] <= mae) {
            cout << ato << endl;
        } else {
            cout << mae << endl;
        }
    }
}
