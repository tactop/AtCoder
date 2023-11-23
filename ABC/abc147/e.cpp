#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}
int H, W;
int MAX = 26000;
int dp[80][80][26000];

int main() {
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    rep(i, 0, H) {
        rep(j, 0, W) { cin >> A[i][j]; }
    }
    rep(i, 0, H) {
        rep(j, 0, W) { cin >> B[i][j]; }
    }
    rep(a, 0, 80) {
        rep(b, 0, 80) {
            rep(c, 0, MAX) { dp[a][b][c] = 0; }
        }
    }
    int zero = 13000;

    dp[0][0][zero + (A[0][0] - B[0][0])] = 1;
    rep(a, 0, H) {
        rep(b, 0, W) {
            int sa = A[a][b] - B[a][b];
            int sa2 = B[a][b] - A[a][b];
            if(a == 0) {
                if(b == 0) {
                    dp[0][0][zero + sa] = 1;
                    dp[0][0][zero + sa2] = 1;
                } else {
                    rep(i, 0, MAX) {
                        if(dp[a][b - 1][i] == 1) {
                            dp[a][b][i + sa] = 1;
                            dp[a][b][i + sa2] = 1;
                        }
                    }
                }
            } else {
                if(b == 0) {
                    rep(i, 0, MAX) {
                        if(dp[a - 1][b][i] == 1) {
                            dp[a][b][i + sa] = 1;
                            dp[a][b][i + sa2] = 1;
                        }
                    }
                } else {
                    rep(i, 0, MAX) {
                        if(dp[a][b - 1][i] == 1) {
                            dp[a][b][i + sa] = 1;
                            dp[a][b][i + sa2] = 1;
                        }
                    }
                    rep(i, 0, MAX) {
                        if(dp[a - 1][b][i] == 1) {
                            dp[a][b][i + sa] = 1;
                            dp[a][b][i + sa2] = 1;
                        }
                    }
                }
            }
        }
    }
    int min = MAX + 1;
    rep(i, 0, MAX) {
        if(dp[H - 1][W - 1][i] == 1) {
            int t = abs(zero - i);
            if(t < min) {
                min = t;
            }
        }
    }
    cout << min << endl;
}