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
    string S;
    cin >> S;
    int a = stoi(S.substr(0, 2));
    int b = stoi(S.substr(2, 2));
    if(a > 0 && a <= 12) {
        if(b > 0 && b <= 12) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if(b > 0 && b <= 12) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }
}