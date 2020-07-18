#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
int main() {
    int N;
    cin>>N;
    vector<pair<int,int>> xy(N);
    rep(i,0,N){
        cin>>xy[i].first>>xy[i].second;
    }
    double sum=0;
    for(int i=0;i<N-1;i++){
        for(int r=i+1;r<N;r++){
            int xx=pow(xy[i].first-xy[r].first,2);
            int yy=pow(xy[i].second-xy[r].second,2);
            sum+=sqrt(xx+yy);
            //printf("%.16f", sum);
        }
    }
    printf("%.16f", sum*2.0/N);
}
