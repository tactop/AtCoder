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
    vector<long long> ve(N);
    rep(i, 0, N) { cin >> ve[i]; }
    long long mae = ve[0] - 1;
    bool yn = true;
    rep(i, 1, N) {
        if(mae > ve[i]) {
            yn = false;
        } else if(mae != ve[i]) {
            mae = ve[i] - 1;
        } else {
            mae = ve[i];
        }
    }
    if(yn) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}