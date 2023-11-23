#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

const int nmax=100;
bool graph[nmax][nmax];
bool visited[nmax];

int dfs(int v,int N,bool visited[nmax]){
    if(visited[v])return 0;
    visited[v]=true;
    int ret=0;
    for(int i=0;i<N;i++){
        if(!graph[v][i]) continue;
        graph[i][v]=false;
        if(dfs(i,N,visited)==0)return 0;
    }
    return 1;

}
int main(){
    int N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int A,B;
        cin >> A >>B;
        graph[A-1][B-1]=true;
        graph[B-1][A-1]=true;
    }

    for(int i=0;i<nmax;i++){
        visited[i]=false;
    }
    int ret=0;
    for(int i=0;i<N;i++){
        ret+=dfs(i,N,visited);
    }
    cout << ret <<endl;
    return 0;
}

