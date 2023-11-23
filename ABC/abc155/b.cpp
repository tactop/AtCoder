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
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, 0, N) { cin >> v[i]; }
    bool j = true;
    rep(i, 0, N) {
        if(v[i] % 2 == 0) {
            if(v[i] % 3 != 0 && v[i] % 5 != 0) {
                j = false;
            }
        }
    }
    if(j) {
        cout << "APPROVED" << endl;
    } else {
        cout << "DENIED" << endl;
    }
}