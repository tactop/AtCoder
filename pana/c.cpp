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
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int n;
vector<string> res;
char al[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
void solve(string tmp, int shiyou) {
    if(tmp.size() == n) {
        res.push_back(tmp);
    } else {
        rep(i, 0, shiyou + 2) {

            if(i != shiyou + 1) {
                solve(tmp + al[i], shiyou);
            } else {
                solve(tmp + al[i], shiyou + 1);
            }
        }
    }
}
int main() {

    cin >> n;
    solve("a", 0);
    for(string t : res) {
        cout << t << endl;
    }
}
