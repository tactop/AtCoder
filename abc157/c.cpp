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

long long GetDigit(long long num) { return std::to_string(num).length(); }
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(M);
    vector<char> c(M);
    rep(i, 0, M) {
        cin >> s[i];
        cin >> c[i];
    }
    bool kekka = false;
    rep(i, 0, 1000) {
        string tmp = to_string(i);
        bool k = true;
        if(tmp.length() != N) {
            continue;
        }
        rep(j, 0, M) {
            if(s[j] > N || tmp[s[j] - 1] != c[j]) {

                k = false;
            }
        }
        if(k) {
            kekka = true;
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
