#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
const int ININF = 1000000;
long long longPow(int n) {
    long long res = 1;
    rep(i, 0, n) { res *= 2; }
    return res;
}

int main() {
    long long N, K;
    cin >> N >> K;
    vector<double> p(N);
    rep(i, 0, N) { cin >> p[i]; }
    double tmp = 0.0;
    rep(i, 0, K) { tmp += (p[i] + 1.0) / 2.0; }
    double m = tmp;
    rep(i, 1, N - K + 1) {
        tmp -= (p[i - 1] + 1.0) / 2.0;
        tmp += (p[i + K - 1] + 1.0) / 2.0;
        if(m < tmp) {
            m = tmp;
        }
    }
    //cout << m << endl;
     cout << setprecision(10) << m << endl;
}
