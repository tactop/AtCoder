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
ll R, B, x, y;
bool che2(ll r, ll b) {
    if(r * x + b > R || b * y + r > B) {
        return false;
    } else {
        return true;
    }
}
bool che(ll x) {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = R;

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;
        if(che2(mid, x - mid)) {
            right = mid;
            return true;
        } else {
            left = mid;
        }
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている
     */
    return left;
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right =
        1000000000000000001; // 「index =
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
    return left;
}
int main() {
    cin >> R >> B >> x >> y;
    cout << binary_search() << endl;
}
