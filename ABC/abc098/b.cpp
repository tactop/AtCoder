#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
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
    string s;
    cin >> N >> s;
    int ans = 0;
    rep(i, 0, N - 1) {
        set<char> se1;
        set<char> se2;
        rep(j, 0, N) {
            if(i >= j) {
                se1.insert(s[j]);
            } else {
                se2.insert(s[j]);
            }
        }
        int syu = 0;
        for(auto ss : se1) {
            if(se2.count(ss) != 0) {
                syu++;
            }
        }
        chmax(ans, syu);
    }
    cout << ans << endl;
}