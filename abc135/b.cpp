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
    int N;
    cin >> N;
    int P[50];
    rep(i, 0, N) { cin >> P[i]; }
    int count = 0;
    rep(i, 0, N) {
        if(P[i] != i + 1) {
            count++;
        }
    }
    if(count == 0 || count == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}