#include <algorithm>
#include <cmath>
#include <iomanip>
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
    long long A, B, K;
    cin >> A >> B >> K;
    if(A >= K) {
        cout << A - K << " " << B << endl;
    } else if(A + B >= K) {
        cout << 0 << " " << A + B - K << endl;
    } else {
        cout << 0 << " " << 0 << endl;
    }
}