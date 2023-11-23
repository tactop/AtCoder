#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <utility>
using namespace std;
//2がAC
struct UnionFind
{
    vector<int> par;
    vector<int> rank;

    UnionFind(int N) : par(N), rank(N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i]=0;
        }
    }
    int root(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            return par[x] = root(par[x]);
        }
    }
    int size(int x)
    {
        return rank[root(x)];
    }
    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
        {
            return;
        }
        if(rank[rx]<rank[ry]){
            par[rx]=ry;
        }


    }
    bool same(int x,int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> AB(M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        AB[i].first = a - 1;
        AB[i].second = b - 1;
    }
    long long ans[M];
    UnionFind uf(N);
    ans[M - 1] = N * (N - 1) / 2;
    for (int i = M - 1; i > 0; i--)
    {
        if (uf.same(AB[i].first, AB[i].second))
        {
            ans[i - 1] = ans[i];
        }
        else
        {
            int asize = uf.size(AB[i].first);
            int bsize = uf.size(AB[i].second);
            uf.unite(AB[i].first, AB[i].second);
            ans[i - 1] = ans[i] - asize * bsize;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cout << ans[i] << endl;
    }
}