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
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    rep(i, 0, N) { cin >> A[i]; }
    rep(i, 0, N) { cin >> B[i]; }
    rep(i, 0, N - 1) { cin >> C[i]; }
    int res = 0;
    int tmp = -5;
    rep(i, 0, N) {
        int r = A[i] - 1;
        res += B[r];
        if(r == tmp + 1) {
            res += C[tmp];
        }
        tmp = r;
    }
    cout << res << endl;
}