#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
using namespace std;

int main() {
    int N;
    cin >> N;
    int mon[N];
    int gcdN;
    for (int i = 0; i < N; ++i){
        cin >> mon[i];
        if(i==0){
           gcdN = mon[i];
        }else{
            gcdN = gcd(gcdN,mon[i]);
        }
    }
    cout << gcdN << endl;
}