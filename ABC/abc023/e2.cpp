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

    vector<int> f(n);
    rep(i, 0, n) {
        int t = s[i] - '0';
        if(i == 0) {
            if(t <= 5) {
                count += t;
            } else {
                count = 11 - t;
                f[i] = 1;
            }
        } else {
            if(f[i - 1] == 1) {
                if(t <= 4) {
                    count += t;
                } else {
                    if(f[i - 1] == 1) {
                        count += 9 - t;
                    }
                    f[i] = 1;
                }
            } else {
                if(t <= 5) {
                    count += t;
                } else {
                    {
                        if(s[i - 1] == '5') {
                            count--;
                        }
                        count += 11 - t;
                        f[i] = 1;
                    }
                }
            }
        }
    }
    cout << count << endl;
}
