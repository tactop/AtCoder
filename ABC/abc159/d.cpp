#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
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
int main() {
    int N;
    long long zen=0LL;
    cin >> N;
    vector<long long> A(N);
    vector<long long> count(N + 1);
    rep(i, 0, N) {
        cin >> A[i];
        count[A[i]]++;
    }
    rep(i, 1, N + 1) {
        // cout << "ci:"<<count[i] << endl;
        zen += count[i] * (count[i] - 1)/2;
    }
    //cout << "zen:" << zen << endl;
    rep(i, 0, N) {
        long long res = zen - count[A[i]] * (count[A[i]] - 1)/2;
        if(count[A[i]] > 0) {
            res += (count[A[i]] - 1) * (count[A[i]] - 2)/2;
        }
        cout << res << endl;
    }
}
