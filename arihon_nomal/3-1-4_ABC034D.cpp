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
#define vein(v, n)                                                             \
    v.assign(n, 0);                                                            \
    for(int i = 0; i < n; i++) {                                               \
        cin >> v[i];                                                           \
    }
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

long long N, K;
vector<pair<ll, ll>> ve;

bool isOK(long double val) {
    vector<long double> n(N);
    rep(i, 0, N) { n[i] = ve[i].first * (ve[i].second - val); }
    sort(n.begin(), n.end(), greater<long double>());
    long double tmpsum = 0;
    rep(i, 0, K) { tmpsum += n[i]; }
    return tmpsum < 0;
}

// 汎用的な二分探索のテンプレ
long double binary_search() {
    long double left =
        -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    long double right = 100;
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 0.000000001) {
        long double mid = left + (right - left) / 2;

        if(isOK(mid))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right
     * は条件を満たす最小の値になっている*/
    return right;
}

int main() {
    cin >> N >> K;
    ve.assign(N, pair<ll, ll>());
    rep(i, 0, N) { cin >> ve[i].first >> ve[i].second; }
    long double res = binary_search();
    cout << setprecision(16) << res << endl;
}