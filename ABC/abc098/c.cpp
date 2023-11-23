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
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int N;
    string s;
    cin >> N >> s;
    vector<int> le(N);
    vector<int> ri(N);
    rep(i, 0, N) {
        if(i != 0) {
            le[i] = le[i - 1];
            ri[i] = ri[i - 1];
        }
        if(s[i] == 'E') {
            le[i]++;
        } else {
            ri[i]++;
        }

        // cout << ri[i] << "," << le[i] << endl;
    }
    int cost = 1000000;
    rep(i, 0, N) {
        int tcost = 0;
        if(i != 0) {
            tcost += ri[i - 1];
        }
        if(i != N - 1) {
            tcost += le[N - 1] - le[i];
        }
        chmin(cost, tcost);
    }
    cout << cost << endl;
}
