#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
#define vein(v, n)                                                             \
    for(int i = 0; i < n; i++) {                                               \
        cin >> v[i];                                                           \
    }
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

long long N, K;
vector<long long> a;
vector<long long> b;

// index が条件を満たすかどうか
// K以上あったらOK
bool isOK(ll val, ll key) {
    ll sum = 0;
    rep(i, 0, N) {
        sum += upper_bound(b.begin(), b.end(), val / a[i]) - b.begin();
    }
    return sum >= K;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = a[N - 1] * b[N - 1] + 1;
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;

        if(isOK(mid, key))
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
    a.assign(N, 0);
    b.assign(N, 0);
    vein(a, N);
    vein(b, N);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << binary_search(K) << endl;
}