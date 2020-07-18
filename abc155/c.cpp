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

int main() {
    int N;
    cin >> N;
    map<string, int> m;
    rep(i, 0, N) {
        string a;
        cin >> a;
        m[a]++;
    }
    vector<string> v;
    int mm = 0;
    for(auto t : m) {
        if(mm < t.second) {
            mm = t.second;
        }
    }
    for(auto t : m) {
        if(mm == t.second) {
            v.push_back(t.first);
        }
    }
    sort(v.begin(), v.end());

    rep(i, 0, v.size()) { cout << v[i] << endl; }
}
