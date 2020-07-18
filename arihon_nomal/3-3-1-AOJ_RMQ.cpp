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
// const long long INF = 1LL << 60;
const long long INF = 2147483647; // 2^31-1
int N;
vector<ll> v;
void update(int i, ll x) {
    i += N - 1;
    v[i] = x;
    while(i > 0) {
        i = (i - 1) / 2;
        v[i] = min(v[i * 2 + 1], v[i * 2 + 2]);
    }
}

ll query(int a, int b, int k, int l, int r) {
    //[a,b)区間について
    // ノード k （区間 [l, r) 担当）が答える
    if(r <= a || l >= b) {
        return INF;
    }
    if(a <= l && r <= b) {
        return v[k];
    } else {
        ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(c1, c2);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    N = 1;
    while(N < n) {
        N *= 2;
    }
    v.assign(2 * N - 1, INF);
    vector<ll> cs(q);
    vector<pair<ll, ll>> nums(q);

    rep(i, 0, q) { cin >> cs[i] >> nums[i].first >> nums[i].second; }
    rep(i, 0, q) {
        if(cs[i] == 0) {
            update(nums[i].first, nums[i].second);
        } else {
            cout << query(nums[i].first, nums[i].second + 1, 0, 0, N) << endl;
        }
    }
}