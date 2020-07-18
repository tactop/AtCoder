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
    int N, K, M;
    cin >> N >> K >> M;
    int A[110];
    rep(i, 0, N - 1) { cin >> A[i]; }
    int sum = 0;
    rep(i, 0, N - 1) { sum += A[i]; }
    if(M * N - sum > K) {
        cout << -1 << endl;
    } else {
        if(M * N - sum > 0) {
            cout << M * N - sum << endl;
        } else {
            cout << 0 << endl;
        }
    }
}