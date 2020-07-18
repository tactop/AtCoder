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
    string S;
    cin >> S;
    int N = S.size();
    int P = 2019;
    vector<long long> val(P, 0);
    long long tenfactor = 1;
    long long cur = 0;
    val[cur]++;
    for(int i = 0; i < N; ++i) {
        cur = (cur + (S[N - i - 1] - '0') * tenfactor) % P;
        tenfactor = (tenfactor * 10) % P;
        val[cur]++;
    }
    long long res = 0;
    for(int p = 0; p < P; ++p)
        res += val[p] * (val[p] - 1) / 2;
    cout << res << endl;
    
}
