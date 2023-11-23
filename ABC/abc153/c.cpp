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
    int N, K;
    cin >> N >> K;
    vector<long long> H(N);
    rep(i, 0, N) { cin >> H[i]; }
    if(K >= N) {
        cout << 0 << endl;
    } else {
        long long res = 0;
        sort(H.begin(), H.end(), greater<int>());
        rep(i, 0, N) {
            if(i >= K) {
            //    cout << i << "," << H[i] << endl;
                res += H[i];
            }
        }
        cout << res << endl;
    }
}
