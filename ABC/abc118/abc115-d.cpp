#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
string STRINF = "-";
void chmax(string &a, string b) {
    if(a == STRINF) {
        a = b;
    } else if(a.size() < b.size()) {
        a = b;
    } else if((a.size() == b.size()) && a < b)
        a = b;
    {}
}
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.second > b.second;
    }
}
int B[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[11000];

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> ve(M);
    rep(i, 0, M) { cin >> ve[i]; }
    rep(i, 0, 11000) { dp[i] = STRINF; }
    dp[0] = "";
    rep(i, 0, N + 1) {
        if(dp[i] == STRINF) {
            continue;
        }
        rep(r, 0, M) {
            int a = ve[r];
            chmax(dp[i + B[a]], dp[i] + (char)('0' + a));
        }
    }
    cout << dp[N] << endl;
}
