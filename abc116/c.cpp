#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#include <unordered_map>
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
bool compare_by_a(pair<int, long long> a, pair<int, long long> b) {
    if(a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}
long long N;
void func(long long cur, int use, long long &counter) {
    if(cur > N) {
        return;
    }
    if(use == 0b111) {
        counter++;
    }
    func(cur * 10 + 7, use | 0b001, counter);
    func(cur * 10 + 5, use | 0b010, counter);
    func(cur * 10 + 3, use | 0b100, counter);
}
int main() {
    cin >> N;
    long long res = 0;
    func(0, 0, res);
    cout << res << endl;
}