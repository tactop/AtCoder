#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
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
    int N;
    cin >> N;
    rep(i, N, 1000) {
        int k1 = i / 100;
        int k2 = (i % 100) / 10;
        int k3 = i % 10;
        if(k1 == k2 && k2 == k3) {
            cout << i << endl;
            break;
        }
    }
}