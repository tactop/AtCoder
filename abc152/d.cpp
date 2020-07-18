#include <algorithm>
#include <cmath>
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
    rep(i, 0, n) { res *= 10; }
    return res;
}
unsigned GetDigit(unsigned num) { return log10(num) + 1; }
int main() {
    long long N;
    cin >> N;
    vector<int> dp(N + 1);
    dp[0] = 0;
    rep(i, 1, N + 1) {
        string s = to_string(i);
        int keta = s.length();
        int a = s[0] - '0';
        int b = s[keta - 1] - '0';
        cout << a << "," << b << "," << keta << endl;
        if(b == 0) {
            dp[i] = dp[i - 1];

            continue;
        }
        long long sum = 0;
        rep(i, 1, keta + 1) {
            if(i == 1) {
                if(a == b) {
                    sum += 1;
                }
            } else if(i != keta) {
                sum += longPow(i - 2);
            } else {
                // cout << "a" << endl;
                if(b < a) {
                    sum += longPow(i - 2);
                } else if(b > a) {
                } else {
                    cout << "b" << endl;
                    int naka = atoi(s.substr(1, keta - 2).c_str());
                    naka++;
                    sum += naka;
                }
            }
        }
        dp[i] = dp[i - 1] + sum;
    }
    cout << dp[N] << endl;
}
