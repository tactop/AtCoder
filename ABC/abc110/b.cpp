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
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    int maxx = X;
    int miny = Y;

    rep(i, 0, N) {
        int a;
        cin >> a;
        if(a > maxx) {
            maxx = a;
        }
    }
    rep(i, 0, M) {
        int a;
        cin >> a;
        if(a < miny) {
            miny = a;
        }
    }
    if(maxx >= miny) {
        cout << "War" << endl;
    } else {
        cout << "No War" << endl;
    }
}