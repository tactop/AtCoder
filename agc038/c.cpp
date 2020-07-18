#include <algorithm>
#include <cmath>
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
    map<string, long long> ma;
    rep(i, 0, N) {
        string s;
        cin >> s;
        //ここで受け取った文字列sを辞書順最小にソートする
        sort(s.begin(), s.end());
        ma[s]++;
    }

    long long count = 0;
    for(auto a : ma) {
        count += a.second * (a.second - 1) / 2;
    }
    cout << count << endl;
}