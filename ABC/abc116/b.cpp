#include <algorithm>
#include <cmath>
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
    string s;
    cin >> s;
    int res = 0;
    int sa = 1000;
    rep(i, 0, s.size() - 2) {
        int tmp = 100 * (s[i] - '0') + 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
        if(abs(tmp - 753) < sa) {
            res = tmp;
            sa = abs(tmp - 753);
        }
    }
    cout << sa << endl;

}