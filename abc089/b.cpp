#include <algorithm>
#include <cmath>
#include <functional>
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
int rui(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return rui(a, b - 1) * a;
}
int main() {
    set<string> all;
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, 0, N) {
        cin >> s[i];
        all.insert(s[i]);
    }
    int M;
    cin >> M;
    vector<string> t(M);
    rep(i, 0, M) {
        cin >> t[i];
        all.insert(t[i]);
    }
    int max = -1000000000;
    for(auto st : all) {
        int tmp = 0;
        rep(i, 0, N) {
            if(st == s[i]) {
                tmp++;
            }
        }
        rep(i, 0, M) {
            if(st == t[i]) {
                tmp--;
            }
        }
        chmax(max, tmp);
    }
    if(max < 0) {
        cout << 0 << endl;
    } else {
        cout << max << endl;
    }
}