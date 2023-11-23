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
    int N;

    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    rep(i, 0, N) { cin >> P[i]; }
    rep(i, 0, N) { cin >> Q[i]; }
    int kai[9];
    kai[0] = 1;
    rep(i, 1, 9) { kai[i] = kai[i - 1] * i; }

    vector<int> pshiyou(9);
    int pJun = 1;
    rep(i, 0, N) {
        int tmpjun = P[i];
        rep(j, 1, P[i]) {
            if(pshiyou[j] == 1)
                tmpjun--;
        }
        pJun += (tmpjun - 1) * kai[N - i - 1];
        pshiyou[P[i]] = 1;
    }
    vector<int> qshiyou(9);
    int qJun = 1;
    rep(i, 0, N) {
        int tmpjun = Q[i];
        rep(j, 1, Q[i]) {
            if(qshiyou[j] == 1)
                tmpjun--;
        }
        qJun += (tmpjun - 1) * kai[N - i - 1];
        qshiyou[Q[i]] = 1;
    }

    // cout << pJun << endl;
    // cout << qJun << endl;
    int res = pJun - qJun;
    if(res < 0) {
        res *= -1;
    }
    cout << res << endl;
}
