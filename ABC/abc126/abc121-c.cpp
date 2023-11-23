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
    int N, K;
    cin >> N >> K;
    double res = 0;
    double n1 = 1 / (double)N;
    int r = 1;
    for(int i = N; i > 0; i--) {
        // cout << "i:" << i << endl;
        if(i >= K) {
            res += n1;
            // cout << n1 << endl;
            continue;
        }

        while(i *intruijo(2, r) < K) {

            r++;
        }
        res += n1 * ruijo(0.5, r);
        // cout << "r:"<<r<<"res:"<< n1 * ruijo(0.5, r) << endl;
    }
    // cout << res<< endl;
    printf("%.13f\n", res);

}