#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    const double PI = 3.14159265358979323846;
    double a, b, x;
    cin >> a >> b >> x;
    double ans;

    if(x == a * a * b) {
        ans = 0;
    } else if(2 * x > a * a * b) {
        ans = 180.0 * atan((2.0 * (a * a * b - x)) / (a * a * a)) / PI;
    } else {
        ans = 180.0 * atan((a * b * b)/(2*x)) / PI;
    }
    cout << fixed << setprecision(10) << ans << endl;
}