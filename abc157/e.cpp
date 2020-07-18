#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}

int main() {
    int N;
    string S;
    int Q;
    cin >> N >> S >> Q;
    vector<vector<char>> qe(Q);
    rep(i, 0, Q) {
        vector<char> ve(3);
        cin >> ve[0] >> ve[1] >> ve[2];
        qe.push_back(ve);
    }
    rep(i, 0, Q) {
        if(qe[i][0] == '1') {
            int change = qe[i][1] - '0' - 1;
            char c = qe[i][2];
            S[change] = c;
        }else{
            int l= qe[i][1] - '0' - 1;
            int r= qe[i][2] - '0' - 1;
            

        }
    }
}