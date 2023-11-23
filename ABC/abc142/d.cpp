#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
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

int main() {
    long long A, B;
    cin >> A >> B;
    vector<pair<long long, long long>> asoin = prime_factorize(A);
    vector<pair<long long, long long>> bsoin = prime_factorize(B);
    vector<pair<long long, long long>> kouyaku;
    for(auto as : asoin) {
        for(auto bs : bsoin) {
            if(as.first == bs.first) {
                kouyaku.push_back(
                    make_pair(as.first, min(as.second, bs.second)));
            }
        }
    }
    kouyaku.push_back(make_pair(1, 1));
    // for(auto k : kouyaku) {
    //     cout << k.first << "," << k.second << endl;
    // }
    cout << kouyaku.size() << endl;
}