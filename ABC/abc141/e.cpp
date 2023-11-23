#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
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
vector<vector<long long>> kiroku;

void solve(int a, long long zan) {}

int main() {
    int N;
    string S;
    cin >> N >> S;
    int max = 0;
    rep(i, 1, N) {
        string kouho = S.substr(i - max, max + 1);
        rep(r, 0, i - 2 * max) {
            string tmp = S.substr(r, max + 1);
            if(tmp == kouho) {
                max++;
                break;
            }
        }
    }
    cout<<max<<endl;
}