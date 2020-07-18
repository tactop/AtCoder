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
    long long N, K;
    cin >> N >> K;
    long long res = 1;
    vector<long long> ruiL(N + 1);
    vector<long long> ruiR(N + 1);
    ruiL[0] = 0;
    ruiR[0] = N;
    rep(i, 1, N + 1) {
        ruiL[i] = ruiL[i - 1] + i;
        ruiR[i] = ruiR[i - 1] + N - i;
    }
    rep(i, 0, N) {
        int t = N - i;
        if(t < K) {
            break;
        }
        long long s = ruiL[i];
        long long u = ruiR[i];
        res += u - s + 1;
        res = res % MOD;
    }
    cout << res << endl;
}
