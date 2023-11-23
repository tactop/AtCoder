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
bool is_prime(const unsigned n) {
    switch(n) {
    case 0: // fall-through
    case 1:
        return false;
    case 2:
        return true;
    } // n > 2 が保証された

    if(n % 2 == 0)
        return false;

    // 上で i=2 相当は調べたので、i=3から奇数のみ調べる
    for(unsigned i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            return false;
    }

    return true;
}
int main() {
    int N;
    cin >> N;
    vector<int> p;
    rep(i, 0, 400) {
        if(is_prime(i * 5 + 1)) {
            p.push_back(i * 5 + 1);
        }
    }
    rep(i, 0, N) {
        cout << p[i];
        if(i != N - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
