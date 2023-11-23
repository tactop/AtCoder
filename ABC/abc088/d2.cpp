#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
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
    int N, K;
    cin >> N >> K;
    long long res = 0LL;
    if(K==0){
        cout<<N*N<<endl;
        return 0;
    }
    rep(i, K + 1, N + 1) {
        int c = i - K;
        int m = N % i;
        res += (N / i) * c;
        if(m >= K) {
            // cout<<"a:"<<c + ((N - K) / i - 1) * c+ (m - K + 1)<<endl;
            res += m - K + 1;
        }
    }
    cout << res << endl;
}
