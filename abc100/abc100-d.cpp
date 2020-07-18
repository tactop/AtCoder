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
long long ruijo(int x, int n) {
    long long res = 1;
    rep(i, 0, n) { res *= x; }
    return res;
}
//約数を列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}
int main() {
    long long N, M;
    cin >> N >> M;
    long long fl[1010][3];
    rep(i, 0, N) { cin >> fl[i][0] >> fl[i][1] >> fl[i][2]; }
    long long res = 0;
    rep(a, 0, 2) {
        rep(b, 0, 2) {
            rep(c, 0, 2) {
                vector<long long> sum;
                rep(i, 0, N) {
                    long long x=fl[i][0];
                    long long y=fl[i][1];
                    long long z=fl[i][2];
                    if(a == 1) {
                        x = -x;
                    }
                    if(b == 1) {
                        y = -y;
                    }
                    if(c == 1) {
                        z = -z;
                    }
                    sum.push_back(x + y + z);
                }
                sort(sum.begin(), sum.end(), greater<long long>());
                long long Msum = 0;
                rep(i, 0, M) { Msum += sum[i]; }
                chmax(res, Msum);
            }
        }
    }

    cout << res << endl;
}