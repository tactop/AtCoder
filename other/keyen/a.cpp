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
    int H, W, N;
    int sum = 0;
    int count = 0;
    cin >> H >> W >> N;
    int bi;
    if(H > W) {
        bi = H;
    } else {
        bi = W;
    }
    while(sum < N) {
        sum += bi;
        count++;
    }
    cout << count << endl;
}