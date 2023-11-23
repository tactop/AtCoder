#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
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
    int N;
    cin >> N;
    vector<long long> H(N);
    rep(i, 0, N) { cin >> H[i]; }
    int res = 0;
    long long tmp = H[0];
    int count = 0;
    rep(i, 1, N) {
        if(tmp >= H[i]) {
            count++;
            if(count > res) {
                res = count;
            }

        } else {
            count = 0;
        }
        tmp = H[i];
    }
    cout << res << endl;
}