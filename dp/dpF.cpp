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
string s, t;
int dp[3100][3100] = {0};

int main() {

    cin >> s >> t;
    int snoSize = s.size();
    int tSize = t.size();

    rep(i, 0, snoSize) {
        rep(r, 0, tSize) {
            if(s[i] == t[r]) {
                chmax(dp[i + 1][r + 1], dp[i][r] + 1);
                // cout << "s:" << s[i] << ",t:" << t[i] << endl;
            }
            chmax(dp[i + 1][r + 1], dp[i + 1][r]);
            chmax(dp[i + 1][r + 1], dp[i][r + 1]);
        }
    }

    // cout << dp[snoSize][tSize] << endl;
    string res = "";
    int i = snoSize;
    int r = tSize;
    while(i > 0 && r > 0) {
        if(dp[i][r] == dp[i - 1][r]) {
            --i;
        } else if(dp[i][r] == dp[i][r - 1]) {
            --r;
        } else {
            res = s[i - 1] + res;
            --i, --r;
        }
    }

    cout << res << endl;
}
