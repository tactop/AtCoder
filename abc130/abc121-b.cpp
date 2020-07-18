#include <algorithm>
#include <cmath>
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
    int N, X;
    cin >> N >> X;
    int L[110];
    rep(i, 0, N) { cin >> L[i]; }
    int d = 0;
    int count = 1;
    rep(i, 0, N) {
        if(d + L[i] <= X) {
            count++;
        }
        d = d + L[i];
    }
    cout << count << endl;
}