#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
int main() {
    string S;

    cin >> S;
    if(S == "Sunny") {
        cout << "Cloudy" << endl;
    } else if(S == "Cloudy") {
        cout << "Rainy" << endl;
    } else if(S == "Rainy") {
        cout << "Sunny" << endl;
    }
}