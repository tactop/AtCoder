#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a, b) + min(c, d) << endl;
}
