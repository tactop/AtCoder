#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
vector<pair<long long, long long>> prime_factorize(long long n) {
    vector<pair<long long, long long>> res;
    for(long long p = 2; p * p <= n; ++p) {
        if(n % p != 0)
            continue;
        int num = 0;
        while(n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if(n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
//約数を列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, 0, N) { cin >> a[i]; }
    long long sum = 0;
    rep(i, 0, N) { sum += a[i]; }
    vector<long long> yaku;

    yaku = divisor(sum);
    sort(yaku.begin(), yaku.end(), greater<long long>());
    for(auto p : yaku) {
        cout << p << endl;
    }
}
