#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;


int N;
Graph G;
vector<int> res;
const long long INF = 1LL << 60;

void dfs(int v,int p,int c){
    res[v]=c;
    for(auto e:G[v]){
        if (e.first == p) continue;
        if (e.second & 1) dfs(e.first, v, 1-c);
        else dfs(e.first, v, c);
    }
}

int main() {
    int N;
    int D[100010][3];
    rep(i,0,N){
        pair<int,int> pi;
        int a,b;
        long long c;
        cin >> a>>b>>c;
        int d=0;
        if(c%2==1){d=1;}
        D[i][0]=a;
        D[i][0]=b;
        D[i][0]=c;

    }

int ki[100010];
    for(int i = 0; i < N; i++) {
        ki[i]=0;
    }
        for(int i = 0; i < N; i++) {
        if(D[i][2]==1){
            
        }
    }
    return 0;
}