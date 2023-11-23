#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
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
    vector<long long> a(N);
    vector<long long> b(N);
    rep(i, 0, N) { cin >> a[i]; }
    rep(i, 0, N) { cin >> b[i]; }
    long long kk = 1;
    long long res = 0;
    rep(k, 0, 30) {
        kk *= 2; // kkは2^(k+1)
        vector<long long> ma(N);
        vector<long long> mb(N);
        rep(i, 0, N) {
            ma[i] = a[i] % kk;
            mb[i] = b[i] % kk;
        }
        sort(mb.begin(), mb.end());
        int kosuu = 0;
        rep(i, 0, N) {
            int l1 =
                lower_bound(mb.begin(), mb.end(), kk / 2 - ma[i]) - mb.begin();
            int r1 =
                lower_bound(mb.begin(), mb.end(), kk - ma[i]) - mb.begin() - 1;
            if(l1 != N) {
                kosuu += r1 - l1 + 1;
            }
            int l2 = lower_bound(mb.begin(), mb.end(), kk + kk / 2 - ma[i]) -
                     mb.begin();
            int r2 = lower_bound(mb.begin(), mb.end(), kk * 2 - ma[i]) -
                     mb.begin() - 1;
            if(l1 != N) {
                kosuu += r2 - l2 + 1;
            }
            // if(k < 4) {
            //     cout << "kk:" << kk << " i:" << i << " ma[i]:" << ma[i]
            //          << " l1:" << l1 << " r1:" << r1 << " l2:" << l2
            //          << " r2:" << r2 << endl;
            // }
        }
        // cout << "k:" << k << " kosuu:" << kosuu << endl;
        if(kosuu % 2 != 0) {
            res += kk / 2;
        }
    }
    cout << res << endl;
}
