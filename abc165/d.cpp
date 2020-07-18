#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
const int MOD = 1000000007;
int main() {
    long long A, B, N;
    cin >> A >> B >> N;
    long long i = N;
    if(N >= B - 1) {
        i = B - 1;
    }
    long long res = 1LL * (A * i / B) - A * (i / B);
    cout << res << endl;
}
