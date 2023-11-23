#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int N;
    cin >> N;
    int a = N - N / 2;
    // cout << (double)a / (double)N << endl;
    printf("%.10f\n", (double)a / (double)N);
}