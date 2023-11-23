#include<iostream>
#include <string>

using namespace std;
int main(){
    string S;
    cin >> S;
    long long sum =0;
    int n = S.size();
    for(int i=0; i<(1 << (n-1));++i){
        long long psum=0;
        for (int j=0;j<n;++j){
            psum *=10;
            psum += S[j]-'0'; //数値変換
            if((i & (1<<j)) == 0){
                sum +=psum;
                psum=0;
            }
        }
        //sum+=psum;
    }
    cout << sum <<endl;
}