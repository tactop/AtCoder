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
const int MOD = 1000000007;
int main() {
    // long long a = 201;
    // long long b = 200;
    // cout << 1LL * a * a * a * a * a << endl;
    // cout << 1LL * b * b * b * b * b << endl;
    // cout << (1LL * a * a * a * a * a) - (b * b * b * b * b) << endl;

    long long x;
    cin >> x;
    rep(i, -200, 200) {
        rep(j, -200, 200) {
            long long a = 1LL * i;
            long long b = 1LL * j;
            if((1LL * a * a * a * a * a) - (b * b * b * b * b) == x) {
                cout << a << " " << b << endl;
             return 0;
            }
        }
    }
}
