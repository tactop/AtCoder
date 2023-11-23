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

int main() {
    string s;
    cin >> s;
    int count = 0;
    int n = s.size();

    vector<int> d1(n);
    vector<int> d2(n);
    vector<int> f(n);
    rep(i, 0, n) {
        int t = s[i] - '0';
        if(i == 0) {
            d1[i] += t;
            if(t <= 5) {
                d2[i] += t;
            } else {
                d2[i] = 11 - t;
                f[i] = 1;
            }
        } else {
            d1[i] += d1[i - 1] + t;
            if(f[i - 1] != 1) {
                if(t <= 5) {
                    d2[i] = d2[i - 1] + t;
                } else {
                    d2[i] = d2[i - 1] + 11 - t;
                    f[i] = 1;
                }
            } else {
                int tmp = d2[i - 1] + (9 - t);
                if(d1[i] <= tmp) {
                    d2[i] = d1[1];
                } else {
                    d2[i] = tmp;
                }
            }
        }
    }
    cout << d2[n - 1] << endl;
}
