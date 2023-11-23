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

vector<vector<int>> G;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> H(N);
    G.assign(N, vector<int>());
    rep(i, 0, N) { cin >> H[i]; }
    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int res = 0;
    rep(i, 0, N) {
        bool good = true;
        for(auto v : G[i]) {
            if(H[i] <= H[v]) {
                good = false;
            }
        }
        if(good) {
            res++;
        }
    }
    cout << res << endl;
}
