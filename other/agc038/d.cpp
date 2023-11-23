#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N + 1);
    vector<long long> B(N + 1);
    A[0] = 0;
    B[0] = 0;
    rep(i, 1, N + 1) {
        cin >> A[i];
        B[i] = 0;
    }
    int count = 0;
    rep(i, 1, N + 1) {
        int k = N + 1 - i;
        int sum = 0;
        rep(r, 2, N + 1) {
            if(k * r > N) {
                break;
            }
            sum += B[k * r];
            // cout << "k:" << k << "sum:" << sum << endl;
        }
        // cout << "k:" << k << "sum:" << sum << "Ak:" << A[k] << endl;
        if((sum % 2) != A[k]) {
            B[k] = 1;
            count++;
        }
    }
    cout << count << endl;
    rep(i, 1, N + 1) {
        if(B[i] == 1) {
            cout << i << endl;
        }
    }
}