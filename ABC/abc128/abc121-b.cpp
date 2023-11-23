#include <algorithm>
#include <cmath>
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
const int MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    string S[110];
    int P[110];
    int T[110];
    rep(i, 0, N) {
        cin >> S[i] >> P[i];
        T[i] = 0;
    }
    int res[110];
    rep(i, 0, N) {
        string min = "zzzzzzzzzzzzzzzzz";
        int p = 0;
        int tmp;
        rep(r, 0, N) {
            if(T[r] == 1) {
                continue;
            }
            if(min > S[r]) {
                min = S[r];
                p = P[r];
                tmp = r;
            } else if(min == S[r]) {
                if(p < P[r]) {
                    min = S[r];
                    p = P[r];
                    tmp = r;
                }
            }
        }
        T[tmp] = 1;
        cout << tmp + 1<<endl;
    }
}