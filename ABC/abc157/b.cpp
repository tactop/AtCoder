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
    int a[3][3];
    rep(i, 0, 3) {
        rep(j, 0, 3) { cin >> a[i][j]; }
    }
    int N;
    cin>>N;
    rep(i, 0, N) {
        int b;
        cin >> b;
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if(a[i][j] == b) {
                    a[i][j] = -1;
                }
            }
        }
    }
    int res = false;
    rep(i, 0, 3) {
        if(a[i][0] == -1 && a[i][1] == -1 && a[i][2] == -1) {
            res = true;
        }
    }
    rep(i, 0, 3) {
        if(a[0][i] == -1 && a[1][i] == -1 && a[2][i] == -1) {
            res = true;
        }
    }
    if(a[0][0] == -1 && a[1][1] == -1 && a[2][2] == -1) {
        res = true;
    }
    if(a[0][2] == -1 && a[1][1] == -1 && a[2][0] == -1) {
        res = true;
    }
    if(res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}