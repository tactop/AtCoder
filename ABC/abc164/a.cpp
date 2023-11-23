#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;
const double PI = 3.14159265358979323846;
int main() {
    int s, w;
    cin >> s >> w;
    if(s <= w) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
}
