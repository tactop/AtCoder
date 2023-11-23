#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
const int ININF = 1000000;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
long long solve(long long a,long long b){
    if(a==b){
        return 2*a-2;
    }
    long long lim =a*b-1;
    long long low =1;
    long long high=1LL<<31;
while(high-low>1){
    long long mid=(low+high)/2;
    long long mul=(mid+1)/2*
}
}
int main() {
int Q;
cin>>Q;
rep(i,0,Q){
    long long a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
}
    
}
