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
typedef long long ll;
ll N;
vector<ll> h;
vector<ll> s;
bool che(ll x) {
    vector<ll> v;
    rep(i, 0, N) {
        if(x < h[i]) {
            return false;
        }
        v.push_back((x - h[i]) / s[i]);
    }
    sort(v.begin(), v.end());
    rep(i, 0, N) {
        if(v[i] < i) {
            return false;
        }
    }
    return true;
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = 100000000000000000; // 「index =
                    // a.size()-1」が条件を満たさないこともあるので、初期値は
                    // a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;

        if(che(mid))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている
     */
    return right;
}
int main() {
    cin >> N;
    h.assign(N, 0);
    s.assign(N, 0);
    rep(i, 0, N) { cin >> h[i] >> s[i]; }
    cout << binary_search() << endl;
}
