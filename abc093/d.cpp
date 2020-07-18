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
    int n;
    cin >> n;
    vector<long long> res;
    rep(k, 0, n) {
        int a, b;
        cin >> a >> b;
        int los = 0;
        long long seki = a * b;
        for(int i = a - 1; i >= 0; i--) {
            if((b + 1) * i >= seki) {
                los++;
            } else {
                break;
            }
        }
        for(int i = b - 1; i >= 0; i--) {
            if((a + 1) * i >= seki) {
                los++;
            } else {
                break;
            }
        }
        res.push_back(a - 1 + b - 1 - los);
    }
    rep(i, 0, n) { cout << res[i] << endl; }
}
