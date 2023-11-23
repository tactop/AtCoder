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

using Graph = vector<vector<int>>;

int N;
Graph G;
Graph san;
vector<int> res;
vector<int> sanve;
void sandfs(int v, int p, int c) {
    // cout << "v:" << v << " p:" << p << " c:" << c << endl;
    for(auto e : G[v]) {
        if(e == p) {
            continue;
        }
        if(c == 2) {
            sanve.push_back(e);
            continue;
        }
        if(c < 2) {
            sandfs(e, v, c + 1);
        }
    }
}
int main() {
    cin >> N;
    G.assign(N, vector<int>());
    san.assign(N, vector<int>());
    rep(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, 0, N) {
        sanve.assign(0, 0);
        sandfs(i, -1, 0);
        san[i] = sanve;
        // cout << "i:" << i << endl;
        // for(auto s : san[i]) {
        //     cout << s << ",";
        // }
        // cout << endl;
    }
    
}
