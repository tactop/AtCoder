#include<iostream>
using namespace std;

int main(){
    int N,Y;
    cin >> N >> Y ;
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N-i;j++){
            int sum = 10000*i + 5000*j + 1000*(N-i-j);
            if(sum==Y){
                cout << i << " " << j << " "<< (N-i-j)<<endl;
                return 0;
            }
        }
    }
    cout <<"-1 -1 -1"<<endl;
}