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
    cin >> N;
    vector<int> a(N);
    rep(i, 0, N) { cin >> a[i]; }
    int tmp = 1;
    int count = 0;
    rep(i, 0, N) {
        if(a[i] == tmp) {
            count++;
            tmp++;
        }
    }
    if(count == 0) {
        cout << -1 << endl;
    } else {
        cout << N - count << endl;
    }
}
