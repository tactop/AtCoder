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
long long A, B, X;
long long keta(long long x) { return to_string(x).size(); }
// x が条件を満たすかどうか
bool isOK(long long x) {
    long long d = keta(x);
    if(A * x + B * d <= X) {
        return false;
    }
    return true;
}

// 汎用的な二分探索のテンプレ
long long binary_search() {
    long long left =
        0LL; //「index = 0」が条件を満たすこともあるので、初期値は -1
    long long right =
        1000000001; // 「index =
                    // a.size()-1」が条件を満たさないこともあるので、初期値は
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
    return left;
}
int main() {
    cin >> A >> B >> X;
    cout << binary_search() << endl;
}