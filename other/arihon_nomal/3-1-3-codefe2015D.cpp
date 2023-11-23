//ムズイ！できなかった
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
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

long long N, M;
vector<int> x;

// 花束が作れない時にOK
bool isOK(ll val) { vector<int> d(M); 
d[0]=
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = INF;
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;

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
    cin >> N >> M;
    vein(x, M);
}