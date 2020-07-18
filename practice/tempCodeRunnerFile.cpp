#include<iostream>
#include <string>

using namespace std;
int main(){
    string abcd;
    cin>>abcd;
    int A[4];
    for(int i=0;i<4;i++) A[i]=abcd[i]-'0';
    for(int i=0; i<(1<<3);++i){
        int sum=0;
        string S[4];
        for (int j=0;j<4;++j){
            if((i & (1<<(3-j))) == 0){
                sum+=A[j];
                S[j]="+";
            }else{
                sum-=A[j];
                S[j]="-";
            }
        }
        //cout <<"sum="<<sum<<endl;
        if(sum==7){
            S[3]="=7";
            for(int i=0;i<4;i++)cout <<A[i]<<S[i];
            return 0;
        }
    }

}