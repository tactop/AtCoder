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
    int l = s.size();

    int k = 1;
    int g = 0;
    int R = 1;
    int ve[100000];
    rep(i, 0, l) { ve[i] = 0; }
    rep(i, 1, l) {
        if(s[i] == 'R') {
            if(R % 2 == 0) {
                k++;
            } else {
                g++;
            }
            R++;
        } else if(R != 0) {
            if(R % 2 == 0) {
                ve[i] += k;
                ve[i - 1] += g;
            } else {
                ve[i] += g;
                ve[i - 1] += k;
            }
            k = 0;
            g = 0;
            R = 0;
        }
    }
    int kk = 1;
    int gg = 0;
    int L = 1;
    // rep(i, 0, l) { cout << ve[i] << " "; }
    // cout << endl;
    rep(i, 1, l) {
        int r = l - i - 1;
        if(s[r] == 'L') {
            if(L % 2 == 0) {
                kk++;
            } else {
                gg++;
            }
            L++;
        } else if(L != 0) {
            if(L % 2 == 0) {
                ve[r] += kk;
                ve[r + 1] += gg;
            } else {
                ve[r] += gg;
                ve[r + 1] += kk;
            }
            kk = 0;
            gg = 0;
            L = 0;
        }
    }
    rep(i, 0, l) { cout << ve[i] << " "; }
    cout << endl;
}