#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, 0, H) { cin >> S[i]; }
    bool ok = true;
    rep(i, 0, H) {
        rep(j, 0, W) {
            if(S[i][j] == '#') {
                bool t = false;
                if(i != 0) {
                    if(S[i - 1][j] == '#') {
                        t = true;
                    }
                }
                if(i != H - 1) {
                    if(S[i + 1][j] == '#') {
                        t = true;
                    }
                }
                if(j != 0) {
                    if(S[i][j - 1] == '#') {
                        t = true;
                    }
                }
                if(j != W - 1) {
                    if(S[i][j + 1] == '#') {
                        t = true;
                    }
                }
                if(!t) {
                    ok = false;
                    break;
                }
            }
        }
    }
    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
