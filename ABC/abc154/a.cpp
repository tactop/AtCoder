#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    string s, t;
    int a, b;
    string u;
    cin >> s >> t >> a >> b >> u;
    if(s == u) {
        a--;
    } else {
        b--;
    }
    cout << a << " " << b << endl;
}