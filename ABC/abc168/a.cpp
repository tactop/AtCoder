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
    int n;
    cin >> n;
    int i = n % 10;
    if(i == 2 || i == 4 || i == 5 || i == 7 || i == 9) {
        cout << "hon" << endl;
    } else if(i == 3) {
        cout << "bon" << endl;
    } else {
        cout << "pon" << endl;
    }
}
