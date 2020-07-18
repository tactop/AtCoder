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
int N;
vector<vector<pair<int, int>>> pol;
int solve(int i, vector<int> ve) {
    if(i != N) {
        // cut<<"A"<<i<<endl;
        ve[i] = 1;
        int a = solve(i + 1, ve);
        ve[i] = 0;
        int b = solve(i + 1, ve);
        return max(a, b);
    } else {

//        cout << "B" << i << "ve:";

        bool m = true;
        int ret = 0;
        rep(i, 0, N) {
            // cout << ve[i];
            if(ve[i] == 0) {
                continue;
            } else {
                ret++;
                rep(j, 0, pol[i].size()) {
                    if(ve[pol[i][j].first] != pol[i][j].second) {
                        m = false;
                        break;
                    }
                }
            }
        }
        if(m) {
            // cout << "ok" << endl;
            return ret;
        } else {
            // cout << "ng" << endl;
            return 0;
        }
    }
    
}
int main() {
    cin >> N;
    rep(i, 0, N) {
        int A;
        cin >> A;
        vector<pair<int, int>> t;
        rep(i, 0, A) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            p.first--;
            t.push_back(p);
        }
        pol.push_back(t);
    }
    vector<int> v(N + 1);

    cout << solve(0, v) << endl;
}
