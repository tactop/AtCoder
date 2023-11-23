#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
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
    string S;
    cin >> N >> S;
    long long res = 0LL;
    long long r = 0LL;
    long long g = 0LL;
    long long b = 0LL;
    rep(i, 0, N) {
        if(S[i] == 'R') {
            r++;
        }
        if(S[i] == 'G') {
            g++;
        }
        if(S[i] == 'B') {
            b++;
        }
    }
    res = r * g * b;
    //  cout<<res<<endl;
    rep(i, 1, (N + 2) / 2) {
        rep(j, 1, N - 1) {
            if(j - i < 0 || j + i >= N) {
                continue;
            }
            if(S[j - i] != S[j] && S[j] != S[j + i] && S[j - i] != S[j + i]) {
                res--;
            }
        }
    }
    cout << res << endl;
}
