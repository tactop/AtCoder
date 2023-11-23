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
    string S;
    cin >> S;
    string res = "Yes";
    rep(i, 0, S.size()) {
        if(i % 2 == 0) {
            if(S[i] == 'L') {
                res = "No";
                break;
            }
        } else {
            if(S[i] == 'R') {
                res = "No";
                break;
            }
        }
    }
    cout << res << endl;
}