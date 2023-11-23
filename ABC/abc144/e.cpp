#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
long long N, K;
vector<long long> A;
vector<long long> F;

// x が条件を満たすかどうか
bool isOK(long long x) {
    long long s = K;
    rep(i, 0, N) {
        if(A[i] * F[i] > x) {
            s -= ((A[i] * F[i] - x) + F[i] - 1) / F[i];
        }
    }
    if(s >= 0) {
        return true;
    } else {
        return false;
    }
}

// 汎用的な二分探索のテンプレ
long long binary_search() {
    long long left =
        -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    long long right =
        INF; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は
             // a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        long long mid = left + (right - left) / 2;

        if(isOK(mid))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている
     */
    return right;
}
int main() {
    cin >> N >> K;
    A.assign(N, 0);
    F.assign(N, 0);
    rep(i, 0, N) { cin >> A[i]; }
    rep(i, 0, N) { cin >> F[i]; }
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<long long>());
    // rep(i, 0, N) { cout << A[i] << " "; }
    // cout << endl;
    // rep(i, 0, N) { cout << F[i] << " "; }
    // cout << endl;
    cout << binary_search() << endl;
}