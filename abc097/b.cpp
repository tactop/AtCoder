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
int rui(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return rui(a, b - 1) * a;
}
int main() {
    int X;
    cin >> X;
    int beki[1100];
    rep(i,0,1100){
        beki[i]=0;
    }
    beki[1] = 1;
    rep(i, 2, X) {
        int v = i * i;
        while(v < 1100) {
            beki[v] = 1;
            v *= v;
        }
    }
    rep(i, 0, X) {
        int t = X - i;
        if(beki[t] == 1) {
            cout << t << endl;
            break;
        }
    }
}