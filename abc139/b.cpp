#include <algorithm>
#include <cmath>
#include <iostream>
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
const int MOD = 1000000007;
int main() {
    int A, B;
    cin >> A >> B;
    int res = 0;
    int kuchi = 1;

    rep(i, 0, 20) {
        if(kuchi >= B) {
            break;
        }
        kuchi += A - 1;
        res++;
    }

    cout << res << endl;
}