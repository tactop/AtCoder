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
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> ak(N);
    vector<pair<int, int>> ao(N);
    rep(i, 0, N) { cin >> ak[i].first >> ak[i].second; }
    rep(i, 0, N) { cin >> ao[i].first >> ao[i].second; }
    sort(ao.begin(), ao.end());
    int res = 0;
    rep(i, 0, N) {
        int maxy = -1;
        int maxj = -1;
        rep(j, 0, N) {
            if(ak[j].first < ao[i].first && ak[j].second < ao[i].second &&
               maxy < ak[j].second) {
                maxj = j;
                maxy = ak[j].second;
            }
        }
        if(maxj != -1) {
            ak[maxj].first = 1000;
            ak[maxj].second = 1000;
            res++;
        }
    }
    cout << res << endl;
}
