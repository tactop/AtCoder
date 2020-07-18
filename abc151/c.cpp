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
    int N, M;
    cin >> N >> M;
    vector<int> p(M);
    vector<string> s(M);
    vector<pair<int, int>> ten(N);
    rep(i, 0, M) {
        int pp;
        cin >> pp;
        p[i] = pp - 1;
        cin >> s[i];
    }
    rep(i, 0, N) {
        ten[i].first = 0;
        ten[i].second = 0;
    }
    int ac = 0;
    int pe = 0;
    rep(i, 0, M) {
        if(s[i] == "AC") {
            if(ten[p[i]].first == 0) {
                ac++;
                pe += ten[p[i]].second;
                ten[p[i]].first = 1;
            }
        } else {
            if(ten[p[i]].first == 0) {
                ten[p[i]].second++;
            }
        }
    }
    cout << ac << " " << pe << endl;
}
