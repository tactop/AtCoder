#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int K, X;
    cin>>K>>X;
    if(500 * K >= X) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}