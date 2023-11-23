#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
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
    long long xy[50][2];
    cin >> N;
    rep(i, 0, N) { cin >> xy[i][0] >> xy[i][1]; }
    vector<vector<pair<long long,long long>>> kyori;
    rep(i, 0, N) {
        vector<pair<long long,long long>> ve;
        rep(r, 0, N) {

            pair<long long,long long> p;
            p.first = abs(xy[i][0] - xy[r][0]);
            p.second = abs(xy[i][1] - xy[r][1]);
            ve.push_back(p);
            // cout<<"["<< p.first<<","<< p.second<<"]";
        }
        kyori.push_back(ve);
        // cout<<endl;
    }
    int max = 0;
    rep(i, 0, N) {
        rep(r, 0, N) {
            if(i==r){
                continue;
            }
            int count = 0;
            rep(a, 0, N) {
                rep(b, 0, N) {
                    // cout<<i<<","<<r<<","<<a<<","<<b<<endl;
                    if(kyori[i][r].first == kyori[a][b].first &&
                       kyori[i][r].second == kyori[a][b].second) {
                        count++;
                    }
                }
            }
            if(max < count) {
                max = count;
            }
        }
    }
    // cout << "max:" << max<<endl;
    if(N == 1) {
        cout << 1 << endl;
    }
    cout << N  - max/2 << endl;
}