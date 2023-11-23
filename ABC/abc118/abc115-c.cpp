#include <algorithm>
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
long long GCD(long long a, long long b) { return b ? GCD(b, a % b) : a; }
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    long long res = A[0];
    rep(i, 0, N) { res = GCD(res, A[i]); }
    cout << res << endl;
}