#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    int count = 0;
    int huko = 0;
    int hazi = 0;
    rep(i, 0, N) {
        if(i == 0) {
            if(S[i] == 'L') {
                count++;
                huko++;
                hazi++;
            }
        }
        if(i == N - 1) {
            if(S[i] == 'R') {
                count++;
                huko++;
                hazi++;
            }
        }
        if(i != N - 1) {
            if(S[i] == 'R' && S[i + 1] == 'L') {
                count++;
                huko++;
                huko++;
            }
        }
    }
    //  cout << "count:" << count << ",huko:" << huko << endl;
    if(count == 1) {
        cout << N - 1 << endl;

    } else if(count - 2 >= K) {
        //  cout << "aaaa" << endl;
        cout << N - huko + 2 * K << endl;
    } else {
        //  cout << "bbbb" << endl;
        int p = 2;
        if(hazi == 2) {
            p = 1;
        }
        cout << N - huko + 2 * (count - 2) + p << endl;
    }
}