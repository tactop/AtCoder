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
    vector<long long> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    int max = 0;
    int max2 = 0;
    int maxi = 0;
    rep(i, 0, N) {
        if(max < A[i]) {
            max2 = max;
            max = A[i];
            maxi = i;
        } else if(max2 < A[i]) {
            max2 = A[i];
        }
    }
    rep(i, 0, N) {
        if(i == maxi) {
            cout << max2 << endl;
        } else {
            cout << max << endl;
        }
    }
}