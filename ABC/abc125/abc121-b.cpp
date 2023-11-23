#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int V[21];
    int C[21];
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
        for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    int res=0;
for (int i = 0; i < N; i++)
    {
       if(V[i]>C[i]){
           res+=V[i]-C[i];
       }
    }
    cout << res << endl;
}