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
    long long res = 0;
    long long N, C;
    cin >> N >> C;
    vector<long long> x(N);
    vector<long long> v(N);
    vector<long long> lrui(N);
    vector<long long> lmax(N);
    vector<long long> rrui(N);
    vector<long long> rmax(N);
    rep(i, 0, N) { cin >> x[i] >> v[i]; }
    lrui[0] = -x[0] + v[0];
    lmax[0] = lrui[0];
    rep(i, 1, N) {
        lrui[i] = lrui[i - 1] - (x[i] - x[i - 1]);
        lrui[i] += v[i];
        if(lmax[i - 1] < lrui[i]) {
            lmax[i] = lrui[i];
        } else {
            lmax[i] = lmax[i - 1];
        }
    }
    rrui[0] = -(C - x[N - 1]) + v[N - 1];
    rmax[0] = rrui[0];
    rep(j, 1, N) {
        int i = N - 1 - j;
        rrui[j] = rrui[j - 1] - (x[i + 1] - x[i]);
        rrui[j] += v[i];
        if(rmax[j - 1] < rrui[j]) {
            rmax[j] = rrui[j];
        } else {
            rmax[j] = rmax[j - 1];
        }
    }
   // rep(i, 0, N) { cout << "lrui:" << lrui[i] << ",lmax:" << lmax[i] << endl; }
   // rep(i, 0, N) { cout << "rrui:" << rrui[i] << ",rmax:" << rmax[i] << endl; }
    chmax(res, lmax[N - 1]);
    chmax(res, rmax[N - 1]);
    rep(i, 0, N - 1) {
        long long tmp = lrui[i];
        tmp -= x[i];
        tmp += rmax[N - 2 - i];
        chmax(res, tmp);
    }
    rep(i, 0, N - 1) {
        long long tmp = rrui[i];
        tmp -= C - x[N - 1 - i];
        tmp += lmax[N - 2 - i];
        chmax(res, tmp);
    }
    cout << res << endl;
}
