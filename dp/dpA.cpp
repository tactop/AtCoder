#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
int N;
long long h[100010];
long long dp[100010];
int main()
{
    int N;
    cin >> N;
    rep(i, 0, N) cin >> h[i];
    rep(i, 0, N) dp[i] = INF;
    dp[0] = 0;
    rep(i, 1, N)
    {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1)
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N - 1] << endl;
}