#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    string s;
    cin >> s;
    if(s == "abc" || s == "acb" || s == "bac" || s == "bca" || s == "cab" ||
       s == "cba") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
