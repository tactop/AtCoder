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
    long long W, H, x, y;
    cin >> W >> H >> x >> y;
    long long S = W * H;
    if(S % 2 == 1) {
        S--;
        cout << S / 2 << ".5";
    } else {
        cout << S / 2;
    }
    //     long double max = (long double)S / 2.0;
    // cout << max << " ";
    // printf("%20.1f", max);
    if(x == W / 2 && y == H / 2 && W % 2 == 0 && H % 2 == 0) {
        cout << " " << 1 << endl;
    } else {
        cout << " " << 0 << endl;
    }
}