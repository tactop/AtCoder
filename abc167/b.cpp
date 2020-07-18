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
typedef long long ll;
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
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k <= a) {
        cout << k << endl;
    } else if(k <= a + b) {
        cout << a << endl;
    } else {
        cout << a - (k - a - b) << endl;
    }
}