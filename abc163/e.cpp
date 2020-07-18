#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <numeric>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
long long M = 1000000007;
long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
int main() {
    long long N, K;
    cin >> N >> K;
    long long sum = 0;
    vector<long long> mo;
    rep(i, 1, K + 1) {
        if(i * i < K) {
            mo.push_back(1);
        }
        sum += i;
        sum %= M;
    }
    long long maxm = mo.size();
    vector<set<pair<long long,long long>>> ne(maxm, set<pair<long long,long long>>());
    rep(i, 0, maxm ) {
        rep(j, 1, maxm + 1) { 

         }
    }

    rep(i, 1, N) {}
}
