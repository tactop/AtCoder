#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for (int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int N;
    cin >> N;
    int p[10010];
    rep(i,0,N){
        cin>>p[i];
    }
    int max=0;
    int res=0;
    rep(i,0,N){
        chmax(max,p[i]);
        res+=p[i];
    }
    res-=max/2;
    cout << res << endl;
}