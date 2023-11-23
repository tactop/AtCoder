#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
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
    int A, B;
    cin >> A >> B;
    string res[100];
    rep(i, 0, 50) {
        rep(j, 0, 100) { res[i] += '#'; }
    }
    rep(i, 50, 100) {
        rep(j, 0, 100) { res[i] += '.'; }
    }
    int shiro = A - 1;
    rep(i, 2, 50) {
        rep(j, 0, 100) {
            if(shiro > 0 && i % 2 == 0 && j % 2 == 0) {
                res[i][j] = '.';
                shiro--;
            }
        }
    }
    int kuro = B - 1;
    rep(i, 52, 100) {
        rep(j, 0, 100) {
            if(kuro > 0 && i % 2 == 0 && j % 2 == 0) {
                res[i][j] = '#';
                kuro--;
            }
        }
    }
    cout << "100 100" << endl;
    rep(i, 0, 100) {
        rep(j, 0, 100) { cout << res[i][j]; }
        cout << endl;
    }
}
