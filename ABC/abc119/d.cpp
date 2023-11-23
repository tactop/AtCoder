#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
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
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
const int ININF = 1000000;
long long maxnear(vector<long long> v, long long a) {
    int dai = lower_bound(v.begin(), v.end(), a) - v.begin();
    if(dai == 0) {
        return v[dai] - a;
    } else if(dai == v.size()) {
        return a - v[dai - 1];
    } else {
        return min(v[dai] - a, a - v[dai - 1]);
    }
}

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A + 2);
    vector<long long> t(B + 2);
    vector<long long> q(Q);
    s[0] = -INF;
    t[0] = -INF;
    rep(i, 1, A + 1) { cin >> s[i]; }
    rep(i, 1, B + 1) { cin >> t[i]; }
    s[A + 1] = INF;
    t[B + 1] = INF;
    rep(i, 0, Q) { cin >> q[i]; }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    // vector<long long> sTot(A);
    // vector<long long> tTos(B);
    // rep(i, 0, A) { sTot[i] = maxnear(t, s[i]); }
    // rep(i, 0, B) { tTos[i] = maxnear(s, t[i]); }
    // rep(i, 0, A) { cout << "sTot[" << i << "]:" << sTot[i] << endl; }
    // rep(i, 0, B) { cout << "tTos[" << i << "]:" << tTos[i] << endl; }
    rep(i, 0, Q) {
        long long x = q[i];
        long long minres = INF;
        int sdai = lower_bound(s.begin(), s.end(), x) - s.begin();
        int ssyo = sdai - 1;
        int tdai = lower_bound(t.begin(), t.end(), x) - t.begin();
        int tsyo = tdai - 1;
        chmin(minres,
              (abs(x - s[sdai]) + abs(s[sdai] - t[tdai]) ));
        chmin(minres,
              (abs(x - s[sdai]) + abs(s[sdai] - t[tsyo]) ));
        chmin(minres,
              (abs(x - s[ssyo]) + abs(s[ssyo] - t[tdai]) ));
        chmin(minres,
              (abs(x - s[ssyo]) + abs(s[ssyo] - t[tsyo]) ));
        chmin(minres,
              (abs(x - t[tdai]) + abs(t[tdai] - s[sdai]) ));
        chmin(minres,
              (abs(x - t[tdai]) + abs(t[tdai] - s[ssyo]) ));
        chmin(minres,
              (abs(x - t[tsyo]) + abs(t[tsyo] - s[sdai]) ));
        chmin(minres,
              (abs(x - t[tsyo]) + abs(t[tsyo] - s[ssyo]) ));
        // int tdai = lower_bound(t.begin(), t.end(), x) - t.begin();
        // if(tdai == ) {
        //     chmin(minres, t[tdai] - x + tTos[tdai]);
        // } else if(tdai == t.size()) {
        //     chmin(minres, x - t[tdai-1] + tTos[tdai-1]);
        // } else {
        //     chmin(minres, min(t[tdai] - x + tTos[tdai],
        //                       x - t[tdai - 1] + tTos[tdai - 1]));
        // }
        cout << minres << endl;
    }
}
