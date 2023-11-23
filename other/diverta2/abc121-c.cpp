#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <type_traits>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int N;
    cin >> N;
    vector<int> ve;
    rep(i, 0, N) {
        int p;
        cin >> p;
        ve.push_back(p);
    }
    sort(ve.begin(), ve.end());
    vector<int> pp;
    vector<int> mm;
    long long max = 0;
    rep(i, 0, N / 2) {
        mm.push_back(ve[i]);
        max -= ve[i];
    }
    rep(i, N / 2, N) {
        pp.push_back(ve[i]);
        max += ve[i];
    }
    cout << max << endl;
    if(N % 2 == 0) {
        long long tmp = mm[0];
        rep(i, 0, N - 1) {
            if(i % 2 == 0) {
                cout << pp[i / 2] << " " << tmp << endl;
                tmp = pp[i / 2] - tmp;
            } else {
                cout << mm[i / 2 + 1] << " " << tmp << endl;
                tmp = mm[i / 2 + 1] - tmp;
            }
        }
    } else {
        long long tmp = pp[0];
        rep(i, 0, N - 1) {
            if(i % 2 == 0) {
                cout << mm[i / 2] << " " << tmp << endl;
                tmp = mm[i / 2] - tmp;
            } else {

                cout << pp[i / 2 + 1] << " " << tmp << endl;
                tmp = pp[i / 2 + 1] - tmp;
            }
        }
    }
}