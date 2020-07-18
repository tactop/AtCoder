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
    long long n = 1000000000;
    long long N, K, S;
    cin >> N >> K >> S;
    vector<long long> A(N);
    int nokori = n;
    if(S == n) {
        nokori = 1;
    }
    rep(i, 0, N) {
        if(i < K) {
            cout << S;
        } else {
            cout << nokori;
        }
        if(i != N - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
