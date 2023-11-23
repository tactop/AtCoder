#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
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
    long long K;
    cin >> K;
    vector<long long> run;
    vector<vector<long long>> mae(10, vector<long long>());
    rep(i, 1, 10) {
        mae[i].push_back(i);
        run.push_back(i);
    }
    rep(i, 0, 100) {
        vector<vector<long long>> nex(10, vector<long long>());
        rep(n, 0, 10) {
            for(auto a : mae[n]) {
                if(n != 0) {
                    nex[n-1].push_back(a * 10 + n - 1);
                    run.push_back(a * 10 + n - 1);
                    // cout << "i:" << i << ",n:" << n << ",mae:" << a
                    //      << "plus:" << a * 10 + n - 1 << endl;
                }
                nex[n].push_back(a * 10 + n);
                run.push_back(a * 10 + n);
                // cout << "i:" << i << ",n:" << n << ",mae:" << a
                //      << "plus:" << a * 10 + n << endl;
                if(n != 9) {
                    nex[n+1].push_back(a * 10 + n + 1);
                    run.push_back(a * 10 + n + 1);
                    // cout << "i:" << i << ",n:" << n << ",mae:" << a
                    //      << "plus:" << a * 10 + n + 1 << endl;
                }
            }
        }
        mae = nex;
        if(run.size() >= K) {
            break;
        }
    }
    sort(run.begin(), run.end());
    cout << run[K - 1] << endl;
}
