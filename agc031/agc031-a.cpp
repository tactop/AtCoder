#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> ABC(26);
    vector<char> alf(27);
    alf = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','\0'};
    for (int i = 0; i < N; i++)
    {
        for(int k=0;k<26;k++){
            int ints=S[i];
            int intalf=alf[k];
            if(ints==intalf){
                cout<<"k:"<< k<<"mozi:"<<S[i]<<endl;
                ABC[k].push_back(i);
            }
        }
    }
    long long sum=0;
    for(int i=0;i<26;i++){
        int size=ABC[i].size();
        for(int k=0;k<size;k++){
            if(k+1==size){
              sum+=(N-ABC[i][k])%1000000007;  
            }else{
                sum+=(ABC[i][k+1]-ABC[i][k])%1000000007;
            }
        }
    }
    cout<<sum<<endl;
}