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
int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> h;
    rep(i, 0, N) {
        long long high;
        cin >> high;
        h.push_back(high);
    }
    sort(h.begin(), h.end());
    long long min = INF;
    rep(i, 0, N - K + 1) { chmin(min, h[i + K - 1] - h[i]); }

    cout << min << endl;
}