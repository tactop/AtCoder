#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    string s;
    cin >> s;
    cin >> s;
    int l = s.size();
    int list[6][13];
    rep(i, 0, 6) {
        rep(r, 0, 13) {
            int k = pow(10, i) * r;
            list[i][r] = k % 13;
            cout << list[i][r] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> v;

    vector<int> v1;
    rep(i, 0, 13) {
        if(i == 0) {
            v1.push_back(1);
        } else {
            v1.push_back(0);
        }
    }
    v.push_back(v1);

    rep(i, 1, l + 1) {
        if(s[i - 1] == '?') {
            int w = (i + 1) % 6 - 2;

            vector<int> vv(13);
            rep(t, 0, 13) { vv[t] = 0; }
            rep(t, 0, 10) {
                rep(r, 0, 13) {
                    int n = (r + list[w][t]) % 13;

                    vv[r] += v[i - 1][n] % 1000000007;
                    vv[r] = vv[r] % 1000000007;
                }
            }
            v.push_back(vv);

        } else {
            int w = (i + 1) % 6 - 2;
            vector<int> vv(13);
            int t = (int)s[i - 1];
            rep(r, 0, 13) {
                int n = (r + list[w][t]) % 13;
                vv[r] += v[i - 1][n] % 1000000007;
                vv[r] = vv[r] % 1000000007;
            }

            v.push_back(vv);
        }
    }
    cout << "end" << endl;
    cout << v[l][5] << endl;
}