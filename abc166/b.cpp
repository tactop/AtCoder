#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
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
    int N, K;
    cin >> N >> K;
    vector<int> a(N, 0);
    rep(i, 0, K) {
        int d;
        cin >> d;
        rep(j, 0, d) {
            int t;
            cin >> t;
            t--;
            a[t]++;
        }
    }
    int res = 0;
    rep(i, 0, N) {
        if(a[i] == 0) {
            res++;
        }
    }
    cout << res << endl;
}