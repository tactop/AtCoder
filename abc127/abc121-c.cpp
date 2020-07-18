#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <type_traits>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
double ruijo(double x, int n) {
    double res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
int intruijo(int x, int n) {
    int res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
int main() {
    int N, M;
    cin >> N >> M;
    int LR[100010][2];
    rep(i, 0, M) { cin >> LR[i][0] >> LR[i][1]; }
    int le = 1;
    int ri = N;
    rep(i, 0, M) {
        if(LR[i][0] > le) {
            le = LR[i][0];
        }
        if(LR[i][1] < ri) {
            ri = LR[i][1];
        }
    }
    if(ri < le) {
        cout << 0 << endl;
    } else {
        cout << ri - le + 1 << endl;
    }
}