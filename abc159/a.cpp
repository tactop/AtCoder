#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    cout << N * (N - 1) / 2 + M*(M - 1) / 2 << endl;
}
