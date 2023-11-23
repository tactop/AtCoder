#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
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
int rui(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return rui(a, b - 1) * a;
}
int main() {
    string s;
    bool kekka;
    kekka = true;
    cin >> s;
    string gyaku = s;
    reverse(gyaku.begin(), gyaku.end());
    if(s != gyaku) {
        kekka = false;
    }
    string mae = s.substr(0, s.size() / 2);
    string gmae = mae;
    reverse(gmae.begin(), gmae.end());
    if(mae != gmae) {
        kekka = false;
    }
    string ato = s.substr(s.size() / 2 + 1);
    string gato = ato;
    reverse(gato.begin(), gato.end());
    if(ato != gato) {
        kekka = false;
    }
    if(kekka) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}