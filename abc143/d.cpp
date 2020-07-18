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
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, 0, N) { cin >> L[i]; }
    sort(L.begin(), L.end());
    int count = 0;
    rep(a, 0, N - 2) {
        int c = a + 2;
        int tmp = 0;
        rep(b, a + 1, N - 1) {
            count += c - b - 1;
            for(; c < N; c++) {
                if(L[a] + L[b] > L[c]) {
                    count++;
                } else {
                    break;
                }
            }
        }
    }
    cout << count << endl;
}