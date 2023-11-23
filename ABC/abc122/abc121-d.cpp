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
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
// 多次元 vector 生成
template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

// mod add
const int MOD = 1000000007;
void add(long long &a, long long b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

long long solve(int N) {
    auto dp = make_vec<long long>(N + 1, 5, 5, 5);

    dp[0][0][0][0] = 1;

    rep(i, 0, N) {
        rep(a, 0, 5) {
            rep(b, 0, 5) {
                rep(c, 0, 5) {
                    rep(d, 1, 5) {
                        if(a == 1 && c == 2 && d == 3) {
                            continue;
                        }
                        if(a == 1 && b == 2 && d == 3) {
                            continue;
                        }
                        if(b == 1 && c == 2 && d == 3) {
                            continue;
                        }
                        if(b == 2 && c == 1 && d == 3) {
                            continue;
                        }
                        if(b == 1 && c == 3 && d == 2) {
                            continue;
                        }
                        add(dp[i + 1][b][c][d], dp[i][a][b][c]);
                    }
                }
            }
        }
    }
    long long res = 0;
    rep(i, 1, 5) {
        rep(j, 1, 5) {
            rep(k, 1, 5) { add(res, dp[N][i][j][k]); }
        }
    }
    return res;
}
int main() {
    int N;
    cin >> N;
    cout << solve(N) << endl;
}