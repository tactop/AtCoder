#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
int main() {
    int N;
    cin >> N;
    string s[55];
    int t[55];
    rep(i, 0, N) { cin >> s[i] >> t[i]; }
    string x;
    cin >> x;
    bool sleep = false;
    int res = 0;
    rep(i, 0, N) {
        if(sleep) {
            res += t[i];
        }
        if(s[i] == x) {
            sleep = true;
        }
    }
    cout<<res<<endl;
}