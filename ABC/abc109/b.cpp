#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
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
    string d[110];
    rep(i,0,N){
        cin>>d[i];
    }
    set<string> W;
    int i;
    string mae = "";
    for(i = 0; i < N; i++) {
        string x =d[i];
        bool shiri = true;
        if(i != 0) {
            if(x[0] != mae[mae.size() - 1]) {
                shiri = false;
            }
        }
        if(!shiri || W.count(x) != 0) {
            cout << "No" << endl;
            break;
        } else {
            W.insert(x);
            mae = x;
        }
    }
    if(i == N) {
        cout << "Yes" << endl;
    }
}