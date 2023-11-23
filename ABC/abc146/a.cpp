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
    if(S == "SUN") {
        cout<<7<<endl;
    } else if(S == "MON") {
        cout<<6<<endl;
    } else if(S == "TUE") {
        cout<<5<<endl;
    } else if(S == "WED") {
        cout<<4<<endl;
    } else if(S == "THU") {
        cout<<3<<endl;
    } else if(S == "FRI") {
        cout<<2<<endl;
    } else if(S == "SAT") {
        cout<<1<<endl;
    }
}