#include <algorithm>
#include <cmath>
#include <iomanip>
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
    string S;
    cin >> N >> S;
    int count = 0;
    int tmp = 0;
    rep(i, 0, N) {
        if(S[i] == 'A') {
            tmp = 1;
        } else if(S[i] == 'B') {
            if(tmp == 1) {
                tmp = 2;
            } else {
                tmp = 0;
            }
        } else if(S[i] == 'C') {
            if(tmp == 2) {
                count++;
            }
            tmp = 0;
        } else {
            tmp = 0;
        }
    }
    cout << count << endl;
}