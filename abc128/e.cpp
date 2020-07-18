#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <set>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}

using type = pair<int, long long>; // 1: query, 0: delete, -1: insert
using event = pair<long long, type>;

int main() {
    int N,Q;
    cin>>N>>Q;
    vector<event> v;
    rep(i,0,N){
        int s,t,x;
        cin>>s>>t>>x;
        v.push_back({s-x,type(-1,x)});
        v.push_back({t-x,type(0,x)});
    }
    rep(i,0,Q){
        int d;
        cin>>d;
        v.push_back({d,type(1,i)});
    }
    sort(v.begin(),v.end());
    vector<long long> res(Q);
    multiset<long long> se;
    for(auto p:v){
        long long x=p.first;
           int type =p.second.first;
        long long val =p.second.second;
        if(type==-1){
            se.insert(val);
        }else if(type==0){
            se.erase(se.lower_bound(val));
        }else{
            if(se.empty()){res[val]=-1;}else{
res[val]=*(se.begin());
            }
        }

    }
    for(auto v:res)cout<<v<<endl;

}