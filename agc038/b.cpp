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
    int K, X;
    cin >> K >> X;
    vector<int> ve;
    rep(i, -1000000, 1000001) {
        if(X - K < i && i < X + K) {
            ve.push_back(i);
        }
    }
    rep(i, 0, ve.size()) {
        cout << ve[i];
        if(i != ve.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}