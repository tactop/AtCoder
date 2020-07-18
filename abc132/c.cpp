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
    vector<int> d;
    rep(i, 0, N) {
        int a;
        cin >> a;
        d.push_back(a);
    }
    sort(d.begin(), d.end());
    if(d[N / 2] == d[N / 2 - 1]) {
        cout << 0 << endl;
    } else {
        cout << d[N / 2] - d[N / 2 - 1] << endl;
    }
}