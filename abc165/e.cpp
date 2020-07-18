#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 50;
const int ININF = 1000000;
using pint = pair<int, int>;
using Edge = pair<long long, pint>; //<cost,<u,v>>の形
vector<Edge> edges;

int main() {
    int N, M;
    cin >> N >> M;
    if(N % 2 == 0) {
        rep(i, 1, M + 1) { cout << i << " " << 2 * M - i + 2 << endl; }
    } else {
        rep(i, 1, M + 1) { cout << i << " " << 2 * M - i + 1 << endl; }
    }
}
