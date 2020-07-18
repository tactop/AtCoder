#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
int main() {
    int N, Q;
    long long K;
    cin >> N >> K >> Q;
    vector<int> point(N, 0);
    rep(i, 0, Q) {
        int a;
        cin >> a;
        point[a - 1]++;
    }
    rep(i, 0, N) {
        // cout << "i:" << i << ",point" << point[i] << endl;
        if(point[i] - Q + K > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
