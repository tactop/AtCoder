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
const int ININF = 1000000;
int d[510][510];
int c[510][510];
int main() {
    int N, C;
    cin >> N >> C;
    rep(i, 0, C) {
        rep(j, 0, C) { cin >> d[i][j]; }
    }
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<int>> v(3, vector<int>(C, 0));
    rep(cc, 0, C) {
        rep(i, 0, N) {
            rep(j, 0, N) { v[(i + j) % 3][cc] += d[c[i][j]][cc]; }
        }
    }
    long long min = INF;

    rep(i, 0, C) {
        rep(j, 0, C) {
            if(i == j)
                continue;
            rep(k, 0, C) {
                if(i == k || j == k)
                    continue;
                int sum = v[0][i] + v[1][j] + v[2][k];
                if(sum < min) {
                    min = sum;
                }
            }
        }
    }
    cout << min << endl;
}
