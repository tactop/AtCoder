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
    if(s == "hi" || s == "hihi" || s == "hihihi" || s == "hihihihi" ||
       s == "hihihihihi") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
