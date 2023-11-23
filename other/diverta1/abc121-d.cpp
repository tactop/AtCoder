#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int GCD(long long x, long long y) { return x ? GCD(y % x, x) : y; }
int main() {
    long long N;
    cin >> N;
    long long sum = 0;
    if(N == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(long long i = 1; i * i <= N; i++) {
        if((N - i) % i == 0) {
            long long k = (N - i) / i;
            if(N / k == N % k) {
                sum += (N - i) / i;
                // cout << i << "," << (N - i) / i << endl;
            }
        }
    }
    cout << sum << endl;
}